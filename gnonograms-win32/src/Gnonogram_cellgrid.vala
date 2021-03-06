/* CellGrid class for Gnonograms3
 * Copyright (C) 2010-2011  Jeremy Wootten
 *
    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License along
    with this program; if not, write to the Free Software Foundation, Inc.,
    51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 *
 *  Author:
 *  Jeremy Wootten <jeremwootten@gmail.com>
 */

using Gtk;
using Gdk;
using Cairo;

public class Gnonogram_CellGrid : DrawingArea
{
    public signal void cursor_moved(int r, int c);

    private int _rows;
    private int _cols;
    private int _current_row;
    private int _current_col;
    private double _aw;
    private double _ah;
    private double _wd;
    private double _ht;
    private double _cell_offset;
    private double _cell_body_width;
    private double _cell_body_height;
    private Gdk.Color grid_color;
    private Cairo.Context _cr;
    private CellPattern _filled_cell_pattern;
    private CellPattern _empty_cell_pattern;
    private CellPattern _unknown_cell_pattern;
    private CellPattern cell_pattern;

    private Cairo.Matrix pattern_matrix;

    public Gnonogram_CellGrid(int r, int c)
    {
        _rows=r;
        _cols=c;

        _current_col=-1;
        _current_row=-1;

        this.add_events(
        EventMask.BUTTON_PRESS_MASK|
        EventMask.BUTTON_RELEASE_MASK|
        EventMask.POINTER_MOTION_MASK|
        EventMask.KEY_PRESS_MASK|
        EventMask.KEY_RELEASE_MASK|
        EventMask.LEAVE_NOTIFY_MASK
        );

        this.motion_notify_event.connect(pointer_moved);
        this.leave_notify_event.connect(leave_grid);

        //Gdk.Color.parse("BLACK", out grid_color);
        //grid_color.parse("BLACK");
        Gdk.Color.parse("BLACK", out grid_color);

    }

    public void resize(int r, int c)
    {
        _rows=r;_cols=c;
    }

    public void force_repaint()
    {
        Gtk.Allocation allocation;
        this.get_allocation(out allocation);
        this.queue_draw_area(0,0,allocation.width,allocation.height);
    }

    public void prepare_to_redraw_cells(GameState gs, bool show_grid, CellPatternType patterntype=CellPatternType.NONE)
    {   //stdout.printf(@"In prepare to redraw , game state $gs\n");
        var win=this.get_window();
        if (win==null) return;
        Gtk.Allocation allocation;
        this.get_allocation(out allocation);
        _cr=Gdk.cairo_create(win);
        _cr.set_antialias(Cairo.Antialias.NONE);
        _cr.set_operator(Cairo.Operator.SOURCE);
        _aw=(double)allocation.width;
        _ah=(double)allocation.height;
        _wd=(_aw-2)/(double)_cols;
        _ht=(_ah-2)/(double)_rows;

        var fill_color=Resource.colors[gs,(int) CellState.FILLED];
        var empty_color=Resource.colors[gs,(int) CellState.EMPTY];
        var unknown_color=Resource.colors[gs,(int) CellState.UNKNOWN];


        //win.clear();
        if (show_grid)
        {
            _cell_offset=Resource.CELLOFFSET_WITHGRID;
            //draw_grid();
        }
        else _cell_offset=Resource.CELLOFFSET_NOGRID;

        _cell_body_width=_wd-_cell_offset-1.0;
        _cell_body_height=_ht-_cell_offset-1.0;

        switch (patterntype)
        {
            case CellPatternType.RADIAL:
                _filled_cell_pattern=new CellPattern.radial(_cell_body_width,_cell_body_height,fill_color);
                _empty_cell_pattern=new CellPattern.radial(_cell_body_width,_cell_body_height,empty_color);
                _unknown_cell_pattern=new CellPattern.gdk_rgba(unknown_color);
                break;
            default:
                _filled_cell_pattern=new CellPattern.gdk_rgba(fill_color);
                _empty_cell_pattern=new CellPattern.gdk_rgba(empty_color);
                _unknown_cell_pattern=new CellPattern.gdk_rgba(unknown_color);
                break;
        }
    }

    public void draw_cell(Cell cell, bool highlight=false, bool mark=false)
    {   //stdout.printf(@"draw_cell cell $cell, gamestate $gs\n");
        _cr=Gdk.cairo_create(this.get_window());
        _cr.set_antialias(Antialias.NONE);
        //don't draw cell outside grid.
        if (cell.row<0||cell.row>=_rows||cell.col<0||cell.col>=_cols)
        {
            return;
        }
        /* coords of top left corner of filled part
        /* (excluding grid if present but including highlight line)
         */
        double x=cell.col*_wd +_cell_offset;
        double y= cell.row*_ht +_cell_offset;
        bool error=false;

        switch (cell.state)
        {
            case CellState.ERROR_EMPTY:
                error=true;
                cell_pattern=_empty_cell_pattern;
                break;
            case CellState.EMPTY:
                cell_pattern=_empty_cell_pattern;
                break;
            case CellState.ERROR_FILLED:
                error=true;
                cell_pattern=_filled_cell_pattern;
                break;
            case CellState.FILLED:
                cell_pattern=_filled_cell_pattern;
                break;
            default :
                cell_pattern=_unknown_cell_pattern;
                break;
        }

        pattern_matrix=Cairo.Matrix.identity();
        pattern_matrix.translate(-x,-y);
        cell_pattern.pattern.set_matrix(pattern_matrix);

        draw_cell_body(_cr, cell_pattern, x,y, highlight, error, mark);
    }


    private void draw_cell_body(Cairo.Context _cr, CellPattern cp, double x, double y, bool highlight, bool error, bool mark)
    {
        _cr.set_line_width(0.5);
        _cr.rectangle(x, y, _cell_body_width, _cell_body_height);
        _cr.set_source(cp.pattern);
        _cr.fill();

        if (mark)
        {
            _cr.set_line_width(1.0);
            Gdk.cairo_set_source_color(_cr, Resource.colors[0,(int) CellState.UNKNOWN]);
            _cr.rectangle(x+_cell_body_width/4, y+_cell_body_height/4, _cell_body_width/2, _cell_body_height/2);
            _cr.fill();
        }

        if (error)
        {
            _cr.set_line_width(4.0);
            Gdk.cairo_set_source_color(_cr, Resource.colors[0,(int) CellState.ERROR]);
            _cr.rectangle(x+3, y+3, _cell_body_width-6, _cell_body_height-6);
            _cr.stroke();
        }
        else if (highlight)
        {
            _cr.set_line_width(2.0);
            //Gdk.cairo_set_source_color(_cr, this.style.bg[Gtk.StateType.SELECTED]);
            Gdk.cairo_set_source_color(_cr, style.bg[ Gtk.StateType.SELECTED]);
            _cr.rectangle(x+2, y+2, _cell_body_width-4, _cell_body_height-4);
            _cr.stroke();
        }

    }

    public void draw_grid()
    {   //stdout.printf("In draw grid\n");
        double x1, x2, y1, y2;

        if (_cr==null) return;
        Gdk.cairo_set_source_color(_cr, grid_color);
        _cr.set_dash(Resource.MINORGRIDDASH,0.0);
        _cr.set_line_width(1.0);
        _cr.set_antialias(Antialias.NONE);

        //Draw minor grid (dashed lines)
        x1=0;x2=_aw-1;
        for (int r=0; r<=_rows; r++)
        {
            y1=1.0+r*_ht;
            _cr.move_to(x1,y1);
            _cr.line_to(x2,y1);
            _cr.stroke();
        }
        y1=0; y2=_ah-1;
        for (int c=0; c<=_cols; c++)
        {
            x1=1.0+c*_wd;
            _cr.move_to(x1,y1);
            _cr.line_to(x1,y2);
            _cr.stroke();
        }
        //Draw major grid (solid lines)

        _cr.set_dash(null,0.0);
        _cr.set_line_width(2.0);

        x1=0;x2=_aw-1;
        for (int r=0; r<=_rows; r+=5)
        {
            y1=1+r*_ht;
            _cr.move_to(x1,y1);
            _cr.line_to(x2,y1);
            _cr.stroke();
        }
        y1=0; y2=_ah-1;
        for (int c=0; c<=_cols; c+=5)
        {
            x1=1+c*_wd;
            _cr.move_to(x1,y1);
            _cr.line_to(x1,y2);
            _cr.stroke();
        }
    }

    private bool pointer_moved(Widget w, Gdk.EventMotion e)
    {
        int r= ((int) (e.y/_ah*_rows)).clamp(0,_rows-1);
        int c= ((int) (e.x/_aw*_cols)).clamp(0,_cols-1);
        if(c!=_current_col||r!=_current_row)//only signal when cursor changes cell
        {
            cursor_moved(r,c); //signal connected to controller
        }
        return true;
    }

    private bool leave_grid(Gdk.EventCrossing e)
    {
        if (e.x<0||e.y<0) //ignore false leave events that sometimes occur for unknown reason
        {
            cursor_moved(-1,-1);
        }
        return true;
    }

    private class CellPattern
    {
        public Cairo.Pattern pattern;
//        public CellPattern.rgba(double red, double green, double blue, double alpha)
//        {
//            pattern=new Cairo.Pattern.rgba(red,green,blue,alpha);
//        }
        public CellPattern.gdk_rgba(Gdk.Color cc)
        {
            double red = cc.red;
            double green = cc.green;
            double blue = cc.blue;
            pattern=new Cairo.Pattern.rgba(red,green,blue,1.0);
        }

        public CellPattern.radial(double wd, double ht, Gdk.Color cc)
        {
//            double red = (double)cc.red/65535.0;
//            double green = (double)cc.green/65535.0;
//            double blue = (double)cc.blue/65535.0;
            double red = cc.red;
            double green = cc.green;
            double blue = cc.blue;
            pattern=new Cairo.Pattern.radial(wd*0.25,ht*0.25,0.0,wd*0.5,ht*0.5,wd*0.5-1.0);
            pattern.add_color_stop_rgba(0.0,1.0,1.0,1.0,1.0);
            pattern.add_color_stop_rgba(0.99, red,green,blue,1.0);
            pattern.add_color_stop_rgba(1.0,0.0,0.0,0.0,0.5);
            pattern.add_color_stop_rgba(1.0,0.9,0.9,0.9,1.0);
        }
    }
}
