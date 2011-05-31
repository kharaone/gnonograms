/* My2DCellArray.c generated by valac 0.11.6, the Vala compiler
 * generated from My2DCellArray.vala, do not modify */

/*  Copyright (C) 2010-2011  Jeremy Wootten
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301  USA
 *
 * As a special exception, if you use inline functions from this file, this
 * file does not by itself cause the resulting executable to be covered by
 * the GNU Lesser General Public License.
 * 
 *  Author:
 * 	Jeremy Wootten <jeremwootten@gmail.com>
 */

#include <glib.h>
#include <glib-object.h>
#include <stdlib.h>
#include <string.h>
#include <gobject/gvaluecollector.h>


#define TYPE_MY2_DCELL_ARRAY (my2_dcell_array_get_type ())
#define MY2_DCELL_ARRAY(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), TYPE_MY2_DCELL_ARRAY, My2DCellArray))
#define MY2_DCELL_ARRAY_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), TYPE_MY2_DCELL_ARRAY, My2DCellArrayClass))
#define IS_MY2_DCELL_ARRAY(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), TYPE_MY2_DCELL_ARRAY))
#define IS_MY2_DCELL_ARRAY_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), TYPE_MY2_DCELL_ARRAY))
#define MY2_DCELL_ARRAY_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), TYPE_MY2_DCELL_ARRAY, My2DCellArrayClass))

typedef struct _My2DCellArray My2DCellArray;
typedef struct _My2DCellArrayClass My2DCellArrayClass;
typedef struct _My2DCellArrayPrivate My2DCellArrayPrivate;

#define TYPE_CELL_STATE (cell_state_get_type ())

#define TYPE_CELL (cell_get_type ())
typedef struct _Cell Cell;
typedef struct _ParamSpecMy2DCellArray ParamSpecMy2DCellArray;

struct _My2DCellArray {
	GTypeInstance parent_instance;
	volatile int ref_count;
	My2DCellArrayPrivate * priv;
};

struct _My2DCellArrayClass {
	GTypeClass parent_class;
	void (*finalize) (My2DCellArray *self);
};

typedef enum  {
	CELL_STATE_UNKNOWN,
	CELL_STATE_EMPTY,
	CELL_STATE_FILLED,
	CELL_STATE_ERROR,
	CELL_STATE_COMPLETED
} CellState;

struct _My2DCellArrayPrivate {
	gint _rows;
	gint _cols;
	CellState* _data;
	gint _data_length1;
	gint _data_length2;
};

struct _Cell {
	gint row;
	gint col;
	CellState state;
};

struct _ParamSpecMy2DCellArray {
	GParamSpec parent_instance;
};


static gpointer my2_dcell_array_parent_class = NULL;

gpointer my2_dcell_array_ref (gpointer instance);
void my2_dcell_array_unref (gpointer instance);
GParamSpec* param_spec_my2_dcell_array (const gchar* name, const gchar* nick, const gchar* blurb, GType object_type, GParamFlags flags);
void value_set_my2_dcell_array (GValue* value, gpointer v_object);
void value_take_my2_dcell_array (GValue* value, gpointer v_object);
gpointer value_get_my2_dcell_array (const GValue* value);
GType my2_dcell_array_get_type (void) G_GNUC_CONST;
GType cell_state_get_type (void) G_GNUC_CONST;
#define MY2_DCELL_ARRAY_GET_PRIVATE(o) (G_TYPE_INSTANCE_GET_PRIVATE ((o), TYPE_MY2_DCELL_ARRAY, My2DCellArrayPrivate))
enum  {
	MY2_DCELL_ARRAY_DUMMY_PROPERTY
};
My2DCellArray* my2_dcell_array_new (gint rows, gint cols, CellState init);
My2DCellArray* my2_dcell_array_construct (GType object_type, gint rows, gint cols, CellState init);
void my2_dcell_array_set_all (My2DCellArray* self, CellState s);
gint my2_dcell_array_rows (My2DCellArray* self);
gint my2_dcell_array_cols (My2DCellArray* self);
GType cell_get_type (void) G_GNUC_CONST;
Cell* cell_dup (const Cell* self);
void cell_free (Cell* self);
void my2_dcell_array_set_data_from_cell (My2DCellArray* self, Cell* c);
void my2_dcell_array_set_data_from_rc (My2DCellArray* self, gint r, gint c, CellState s);
CellState my2_dcell_array_get_data_from_rc (My2DCellArray* self, gint r, gint c);
void my2_dcell_array_get_cell (My2DCellArray* self, gint r, gint c, Cell* result);
void my2_dcell_array_get_row (My2DCellArray* self, gint row, CellState** sa, int* sa_length1, gint start);
void my2_dcell_array_set_row (My2DCellArray* self, gint row, CellState* sa, int sa_length1, gint start);
void my2_dcell_array_get_col (My2DCellArray* self, gint col, CellState** sa, int* sa_length1, gint start);
void my2_dcell_array_set_col (My2DCellArray* self, gint col, CellState* sa, int sa_length1, gint start);
void my2_dcell_array_get_array (My2DCellArray* self, gint idx, gboolean iscolumn, CellState** sa, int* sa_length1, gint start);
void my2_dcell_array_set_array (My2DCellArray* self, gint idx, gboolean iscolumn, CellState* sa, int sa_length1, gint start);
void my2_dcell_array_get_region (My2DCellArray* self, gint idx, gboolean iscolumn, CellState** sa, int* sa_length1, gint start, gint end);
void my2_dcell_array_set_region (My2DCellArray* self, gint idx, gboolean iscolumn, CellState* sa, int sa_length1, gint start, gint end);
gint my2_dcell_array_count_all (My2DCellArray* self, CellState s);
gchar* my2_dcell_array_data2text (My2DCellArray* self, gint idx, gint length, gboolean iscolumn);
gchar* utils_block_string_from_cellstate_array (CellState* cs, int cs_length1);
void my2_dcell_array_copy (My2DCellArray* self, My2DCellArray* ca);
static void my2_dcell_array_finalize (My2DCellArray* obj);


My2DCellArray* my2_dcell_array_construct (GType object_type, gint rows, gint cols, CellState init) {
	My2DCellArray* self = NULL;
	CellState* _tmp0_ = NULL;
	CellState* _tmp1_;
	self = (My2DCellArray*) g_type_create_instance (object_type);
	self->priv->_rows = rows;
	self->priv->_cols = cols;
	_tmp0_ = g_new0 (CellState, self->priv->_rows * self->priv->_cols);
	_tmp1_ = _tmp0_;
	self->priv->_data = (g_free (self->priv->_data), NULL);
	self->priv->_data_length1 = self->priv->_rows;
	self->priv->_data_length2 = self->priv->_cols;
	self->priv->_data = _tmp1_;
	my2_dcell_array_set_all (self, init);
	return self;
}


My2DCellArray* my2_dcell_array_new (gint rows, gint cols, CellState init) {
	return my2_dcell_array_construct (TYPE_MY2_DCELL_ARRAY, rows, cols, init);
}


gint my2_dcell_array_rows (My2DCellArray* self) {
	gint result = 0;
	g_return_val_if_fail (IS_MY2_DCELL_ARRAY (self), 0);
	result = self->priv->_rows;
	return result;
}


gint my2_dcell_array_cols (My2DCellArray* self) {
	gint result = 0;
	g_return_val_if_fail (IS_MY2_DCELL_ARRAY (self), 0);
	result = self->priv->_cols;
	return result;
}


void my2_dcell_array_set_data_from_cell (My2DCellArray* self, Cell* c) {
	g_return_if_fail (IS_MY2_DCELL_ARRAY (self));
	self->priv->_data[((*c).row * self->priv->_data_length2) + (*c).col] = (*c).state;
}


void my2_dcell_array_set_data_from_rc (My2DCellArray* self, gint r, gint c, CellState s) {
	g_return_if_fail (IS_MY2_DCELL_ARRAY (self));
	self->priv->_data[(r * self->priv->_data_length2) + c] = s;
}


CellState my2_dcell_array_get_data_from_rc (My2DCellArray* self, gint r, gint c) {
	CellState result = 0;
	g_return_val_if_fail (IS_MY2_DCELL_ARRAY (self), 0);
	result = self->priv->_data[(r * self->priv->_data_length2) + c];
	return result;
}


void my2_dcell_array_get_cell (My2DCellArray* self, gint r, gint c, Cell* result) {
	Cell _tmp0_ = {0};
	g_return_if_fail (IS_MY2_DCELL_ARRAY (self));
	*result = (_tmp0_.row = r, _tmp0_.col = c, _tmp0_.state = self->priv->_data[(r * self->priv->_data_length2) + c], _tmp0_);
	return;
}


void my2_dcell_array_get_row (My2DCellArray* self, gint row, CellState** sa, int* sa_length1, gint start) {
	g_return_if_fail (IS_MY2_DCELL_ARRAY (self));
	{
		gint c;
		c = start;
		{
			gboolean _tmp0_;
			_tmp0_ = TRUE;
			while (TRUE) {
				if (!_tmp0_) {
					c++;
				}
				_tmp0_ = FALSE;
				if (!(c < (start + (*sa_length1)))) {
					break;
				}
				(*sa)[c] = self->priv->_data[(row * self->priv->_data_length2) + c];
			}
		}
	}
}


void my2_dcell_array_set_row (My2DCellArray* self, gint row, CellState* sa, int sa_length1, gint start) {
	g_return_if_fail (IS_MY2_DCELL_ARRAY (self));
	{
		gint c;
		c = 0;
		{
			gboolean _tmp0_;
			_tmp0_ = TRUE;
			while (TRUE) {
				if (!_tmp0_) {
					c++;
				}
				_tmp0_ = FALSE;
				if (!(c < sa_length1)) {
					break;
				}
				self->priv->_data[(row * self->priv->_data_length2) + (c + start)] = sa[c];
			}
		}
	}
}


void my2_dcell_array_get_col (My2DCellArray* self, gint col, CellState** sa, int* sa_length1, gint start) {
	g_return_if_fail (IS_MY2_DCELL_ARRAY (self));
	{
		gint r;
		r = start;
		{
			gboolean _tmp0_;
			_tmp0_ = TRUE;
			while (TRUE) {
				if (!_tmp0_) {
					r++;
				}
				_tmp0_ = FALSE;
				if (!(r < (start + (*sa_length1)))) {
					break;
				}
				(*sa)[r] = self->priv->_data[(r * self->priv->_data_length2) + col];
			}
		}
	}
}


void my2_dcell_array_set_col (My2DCellArray* self, gint col, CellState* sa, int sa_length1, gint start) {
	g_return_if_fail (IS_MY2_DCELL_ARRAY (self));
	{
		gint r;
		r = 0;
		{
			gboolean _tmp0_;
			_tmp0_ = TRUE;
			while (TRUE) {
				if (!_tmp0_) {
					r++;
				}
				_tmp0_ = FALSE;
				if (!(r < sa_length1)) {
					break;
				}
				self->priv->_data[((r + start) * self->priv->_data_length2) + col] = sa[r];
			}
		}
	}
}


void my2_dcell_array_get_array (My2DCellArray* self, gint idx, gboolean iscolumn, CellState** sa, int* sa_length1, gint start) {
	g_return_if_fail (IS_MY2_DCELL_ARRAY (self));
	if (iscolumn) {
		my2_dcell_array_get_col (self, idx, sa, sa_length1, start);
	} else {
		my2_dcell_array_get_row (self, idx, sa, sa_length1, start);
	}
}


void my2_dcell_array_set_array (My2DCellArray* self, gint idx, gboolean iscolumn, CellState* sa, int sa_length1, gint start) {
	g_return_if_fail (IS_MY2_DCELL_ARRAY (self));
	if (iscolumn) {
		my2_dcell_array_set_col (self, idx, sa, sa_length1, start);
	} else {
		my2_dcell_array_set_row (self, idx, sa, sa_length1, start);
	}
}


void my2_dcell_array_get_region (My2DCellArray* self, gint idx, gboolean iscolumn, CellState** sa, int* sa_length1, gint start, gint end) {
	g_return_if_fail (IS_MY2_DCELL_ARRAY (self));
	if (iscolumn) {
		my2_dcell_array_get_col (self, idx, sa, sa_length1, start);
	} else {
		my2_dcell_array_get_row (self, idx, sa, sa_length1, start);
	}
}


void my2_dcell_array_set_region (My2DCellArray* self, gint idx, gboolean iscolumn, CellState* sa, int sa_length1, gint start, gint end) {
	g_return_if_fail (IS_MY2_DCELL_ARRAY (self));
	if (iscolumn) {
		my2_dcell_array_set_col (self, idx, sa, sa_length1, start);
	} else {
		my2_dcell_array_set_row (self, idx, sa, sa_length1, start);
	}
}


void my2_dcell_array_set_all (My2DCellArray* self, CellState s) {
	g_return_if_fail (IS_MY2_DCELL_ARRAY (self));
	{
		gint r;
		r = 0;
		{
			gboolean _tmp0_;
			_tmp0_ = TRUE;
			while (TRUE) {
				if (!_tmp0_) {
					r++;
				}
				_tmp0_ = FALSE;
				if (!(r < self->priv->_rows)) {
					break;
				}
				{
					gint c;
					c = 0;
					{
						gboolean _tmp1_;
						_tmp1_ = TRUE;
						while (TRUE) {
							if (!_tmp1_) {
								c++;
							}
							_tmp1_ = FALSE;
							if (!(c < self->priv->_cols)) {
								break;
							}
							self->priv->_data[(r * self->priv->_data_length2) + c] = s;
						}
					}
				}
			}
		}
	}
}


gint my2_dcell_array_count_all (My2DCellArray* self, CellState s) {
	gint result = 0;
	gint count;
	g_return_val_if_fail (IS_MY2_DCELL_ARRAY (self), 0);
	count = 0;
	{
		gint r;
		r = 0;
		{
			gboolean _tmp0_;
			_tmp0_ = TRUE;
			while (TRUE) {
				if (!_tmp0_) {
					r++;
				}
				_tmp0_ = FALSE;
				if (!(r < self->priv->_rows)) {
					break;
				}
				{
					gint c;
					c = 0;
					{
						gboolean _tmp1_;
						_tmp1_ = TRUE;
						while (TRUE) {
							if (!_tmp1_) {
								c++;
							}
							_tmp1_ = FALSE;
							if (!(c < self->priv->_cols)) {
								break;
							}
							if (self->priv->_data[(r * self->priv->_data_length2) + c] == s) {
								count++;
							}
						}
					}
				}
			}
		}
	}
	result = count;
	return result;
}


gchar* my2_dcell_array_data2text (My2DCellArray* self, gint idx, gint length, gboolean iscolumn) {
	gchar* result = NULL;
	CellState* _tmp0_ = NULL;
	CellState* arr;
	gint arr_length1;
	gint _arr_size_;
	gchar* _tmp1_ = NULL;
	g_return_val_if_fail (IS_MY2_DCELL_ARRAY (self), NULL);
	_tmp0_ = g_new0 (CellState, length);
	arr = _tmp0_;
	arr_length1 = length;
	_arr_size_ = length;
	my2_dcell_array_get_array (self, idx, iscolumn, &arr, &arr_length1, 0);
	_tmp1_ = utils_block_string_from_cellstate_array (arr, arr_length1);
	result = _tmp1_;
	arr = (g_free (arr), NULL);
	return result;
}


void my2_dcell_array_copy (My2DCellArray* self, My2DCellArray* ca) {
	gint _tmp0_;
	gint _tmp1_;
	gint _tmp2_;
	gint rows;
	gint _tmp3_;
	gint _tmp4_;
	gint _tmp5_;
	gint cols;
	g_return_if_fail (IS_MY2_DCELL_ARRAY (self));
	g_return_if_fail (IS_MY2_DCELL_ARRAY (ca));
	_tmp0_ = my2_dcell_array_rows (ca);
	_tmp1_ = my2_dcell_array_rows (self);
	_tmp2_ = MIN (_tmp0_, _tmp1_);
	rows = _tmp2_;
	_tmp3_ = my2_dcell_array_cols (ca);
	_tmp4_ = my2_dcell_array_cols (self);
	_tmp5_ = MIN (_tmp3_, _tmp4_);
	cols = _tmp5_;
	{
		gint r;
		r = 0;
		{
			gboolean _tmp6_;
			_tmp6_ = TRUE;
			while (TRUE) {
				if (!_tmp6_) {
					r++;
				}
				_tmp6_ = FALSE;
				if (!(r < rows)) {
					break;
				}
				{
					gint c;
					c = 0;
					{
						gboolean _tmp7_;
						_tmp7_ = TRUE;
						while (TRUE) {
							CellState _tmp8_;
							if (!_tmp7_) {
								c++;
							}
							_tmp7_ = FALSE;
							if (!(c < cols)) {
								break;
							}
							_tmp8_ = my2_dcell_array_get_data_from_rc (ca, r, c);
							self->priv->_data[(r * self->priv->_data_length2) + c] = _tmp8_;
						}
					}
				}
			}
		}
	}
}


static void value_my2_dcell_array_init (GValue* value) {
	value->data[0].v_pointer = NULL;
}


static void value_my2_dcell_array_free_value (GValue* value) {
	if (value->data[0].v_pointer) {
		my2_dcell_array_unref (value->data[0].v_pointer);
	}
}


static void value_my2_dcell_array_copy_value (const GValue* src_value, GValue* dest_value) {
	if (src_value->data[0].v_pointer) {
		dest_value->data[0].v_pointer = my2_dcell_array_ref (src_value->data[0].v_pointer);
	} else {
		dest_value->data[0].v_pointer = NULL;
	}
}


static gpointer value_my2_dcell_array_peek_pointer (const GValue* value) {
	return value->data[0].v_pointer;
}


static gchar* value_my2_dcell_array_collect_value (GValue* value, guint n_collect_values, GTypeCValue* collect_values, guint collect_flags) {
	if (collect_values[0].v_pointer) {
		My2DCellArray* object;
		object = collect_values[0].v_pointer;
		if (object->parent_instance.g_class == NULL) {
			return g_strconcat ("invalid unclassed object pointer for value type `", G_VALUE_TYPE_NAME (value), "'", NULL);
		} else if (!g_value_type_compatible (G_TYPE_FROM_INSTANCE (object), G_VALUE_TYPE (value))) {
			return g_strconcat ("invalid object type `", g_type_name (G_TYPE_FROM_INSTANCE (object)), "' for value type `", G_VALUE_TYPE_NAME (value), "'", NULL);
		}
		value->data[0].v_pointer = my2_dcell_array_ref (object);
	} else {
		value->data[0].v_pointer = NULL;
	}
	return NULL;
}


static gchar* value_my2_dcell_array_lcopy_value (const GValue* value, guint n_collect_values, GTypeCValue* collect_values, guint collect_flags) {
	My2DCellArray** object_p;
	object_p = collect_values[0].v_pointer;
	if (!object_p) {
		return g_strdup_printf ("value location for `%s' passed as NULL", G_VALUE_TYPE_NAME (value));
	}
	if (!value->data[0].v_pointer) {
		*object_p = NULL;
	} else if (collect_flags & G_VALUE_NOCOPY_CONTENTS) {
		*object_p = value->data[0].v_pointer;
	} else {
		*object_p = my2_dcell_array_ref (value->data[0].v_pointer);
	}
	return NULL;
}


GParamSpec* param_spec_my2_dcell_array (const gchar* name, const gchar* nick, const gchar* blurb, GType object_type, GParamFlags flags) {
	ParamSpecMy2DCellArray* spec;
	g_return_val_if_fail (g_type_is_a (object_type, TYPE_MY2_DCELL_ARRAY), NULL);
	spec = g_param_spec_internal (G_TYPE_PARAM_OBJECT, name, nick, blurb, flags);
	G_PARAM_SPEC (spec)->value_type = object_type;
	return G_PARAM_SPEC (spec);
}


gpointer value_get_my2_dcell_array (const GValue* value) {
	g_return_val_if_fail (G_TYPE_CHECK_VALUE_TYPE (value, TYPE_MY2_DCELL_ARRAY), NULL);
	return value->data[0].v_pointer;
}


void value_set_my2_dcell_array (GValue* value, gpointer v_object) {
	My2DCellArray* old;
	g_return_if_fail (G_TYPE_CHECK_VALUE_TYPE (value, TYPE_MY2_DCELL_ARRAY));
	old = value->data[0].v_pointer;
	if (v_object) {
		g_return_if_fail (G_TYPE_CHECK_INSTANCE_TYPE (v_object, TYPE_MY2_DCELL_ARRAY));
		g_return_if_fail (g_value_type_compatible (G_TYPE_FROM_INSTANCE (v_object), G_VALUE_TYPE (value)));
		value->data[0].v_pointer = v_object;
		my2_dcell_array_ref (value->data[0].v_pointer);
	} else {
		value->data[0].v_pointer = NULL;
	}
	if (old) {
		my2_dcell_array_unref (old);
	}
}


void value_take_my2_dcell_array (GValue* value, gpointer v_object) {
	My2DCellArray* old;
	g_return_if_fail (G_TYPE_CHECK_VALUE_TYPE (value, TYPE_MY2_DCELL_ARRAY));
	old = value->data[0].v_pointer;
	if (v_object) {
		g_return_if_fail (G_TYPE_CHECK_INSTANCE_TYPE (v_object, TYPE_MY2_DCELL_ARRAY));
		g_return_if_fail (g_value_type_compatible (G_TYPE_FROM_INSTANCE (v_object), G_VALUE_TYPE (value)));
		value->data[0].v_pointer = v_object;
	} else {
		value->data[0].v_pointer = NULL;
	}
	if (old) {
		my2_dcell_array_unref (old);
	}
}


static void my2_dcell_array_class_init (My2DCellArrayClass * klass) {
	my2_dcell_array_parent_class = g_type_class_peek_parent (klass);
	MY2_DCELL_ARRAY_CLASS (klass)->finalize = my2_dcell_array_finalize;
	g_type_class_add_private (klass, sizeof (My2DCellArrayPrivate));
}


static void my2_dcell_array_instance_init (My2DCellArray * self) {
	self->priv = MY2_DCELL_ARRAY_GET_PRIVATE (self);
	self->ref_count = 1;
}


static void my2_dcell_array_finalize (My2DCellArray* obj) {
	My2DCellArray * self;
	self = MY2_DCELL_ARRAY (obj);
	self->priv->_data = (g_free (self->priv->_data), NULL);
}


GType my2_dcell_array_get_type (void) {
	static volatile gsize my2_dcell_array_type_id__volatile = 0;
	if (g_once_init_enter (&my2_dcell_array_type_id__volatile)) {
		static const GTypeValueTable g_define_type_value_table = { value_my2_dcell_array_init, value_my2_dcell_array_free_value, value_my2_dcell_array_copy_value, value_my2_dcell_array_peek_pointer, "p", value_my2_dcell_array_collect_value, "p", value_my2_dcell_array_lcopy_value };
		static const GTypeInfo g_define_type_info = { sizeof (My2DCellArrayClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) my2_dcell_array_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (My2DCellArray), 0, (GInstanceInitFunc) my2_dcell_array_instance_init, &g_define_type_value_table };
		static const GTypeFundamentalInfo g_define_type_fundamental_info = { (G_TYPE_FLAG_CLASSED | G_TYPE_FLAG_INSTANTIATABLE | G_TYPE_FLAG_DERIVABLE | G_TYPE_FLAG_DEEP_DERIVABLE) };
		GType my2_dcell_array_type_id;
		my2_dcell_array_type_id = g_type_register_fundamental (g_type_fundamental_next (), "My2DCellArray", &g_define_type_info, &g_define_type_fundamental_info, 0);
		g_once_init_leave (&my2_dcell_array_type_id__volatile, my2_dcell_array_type_id);
	}
	return my2_dcell_array_type_id__volatile;
}


gpointer my2_dcell_array_ref (gpointer instance) {
	My2DCellArray* self;
	self = instance;
	g_atomic_int_inc (&self->ref_count);
	return instance;
}


void my2_dcell_array_unref (gpointer instance) {
	My2DCellArray* self;
	self = instance;
	if (g_atomic_int_dec_and_test (&self->ref_count)) {
		MY2_DCELL_ARRAY_GET_CLASS (self)->finalize (self);
		g_type_free_instance ((GTypeInstance *) self);
	}
}



