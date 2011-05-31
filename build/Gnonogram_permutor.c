/* Gnonogram_permutor.c generated by valac 0.11.6, the Vala compiler
 * generated from Gnonogram_permutor.vala, do not modify */

/*
 *      This program is free software; you can redistribute it and/or modify
 *      it under the terms of the GNU General Public License as published by
 *      the Free Software Foundation; either version 2 of the License, or
 *      (at your option) any later version.
 *      
 *      This program is distributed in the hope that it will be useful,
 *      but WITHOUT ANY WARRANTY; without even the implied warranty of
 *      MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *      GNU General Public License for more details.
 *      
 *      You should have received a copy of the GNU General Public License
 *      along with this program; if not, write to the Free Software
 *      Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 *      MA 02110-1301, USA.
 */

#include <glib.h>
#include <glib-object.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <gobject/gvaluecollector.h>


#define TYPE_GNONOGRAM_PERMUTOR (gnonogram_permutor_get_type ())
#define GNONOGRAM_PERMUTOR(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), TYPE_GNONOGRAM_PERMUTOR, Gnonogram_permutor))
#define GNONOGRAM_PERMUTOR_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), TYPE_GNONOGRAM_PERMUTOR, Gnonogram_permutorClass))
#define IS_GNONOGRAM_PERMUTOR(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), TYPE_GNONOGRAM_PERMUTOR))
#define IS_GNONOGRAM_PERMUTOR_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), TYPE_GNONOGRAM_PERMUTOR))
#define GNONOGRAM_PERMUTOR_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), TYPE_GNONOGRAM_PERMUTOR, Gnonogram_permutorClass))

typedef struct _Gnonogram_permutor Gnonogram_permutor;
typedef struct _Gnonogram_permutorClass Gnonogram_permutorClass;
typedef struct _Gnonogram_permutorPrivate Gnonogram_permutorPrivate;

#define TYPE_CELL_STATE (cell_state_get_type ())
#define _g_free0(var) (var = (g_free (var), NULL))
#define _g_string_free0(var) ((var == NULL) ? NULL : (var = (g_string_free (var, TRUE), NULL)))
typedef struct _ParamSpecGnonogram_permutor ParamSpecGnonogram_permutor;

typedef enum  {
	CELL_STATE_UNKNOWN,
	CELL_STATE_EMPTY,
	CELL_STATE_FILLED,
	CELL_STATE_ERROR,
	CELL_STATE_COMPLETED
} CellState;

struct _Gnonogram_permutor {
	GTypeInstance parent_instance;
	volatile int ref_count;
	Gnonogram_permutorPrivate * priv;
	CellState* perm;
	gint perm_length1;
	gboolean valid;
};

struct _Gnonogram_permutorClass {
	GTypeClass parent_class;
	void (*finalize) (Gnonogram_permutor *self);
};

struct _Gnonogram_permutorPrivate {
	gint _freedom;
	gint n_blocks;
	gint* blocks;
	gint blocks_length1;
	gint _blocks_size_;
	gint size;
	gint* range_start;
	gint range_start_length1;
	gint _range_start_size_;
	gint* range_end;
	gint range_end_length1;
	gint _range_end_size_;
	gint* block_start;
	gint block_start_length1;
	gint _block_start_size_;
};

struct _ParamSpecGnonogram_permutor {
	GParamSpec parent_instance;
};


static gpointer gnonogram_permutor_parent_class = NULL;

gpointer gnonogram_permutor_ref (gpointer instance);
void gnonogram_permutor_unref (gpointer instance);
GParamSpec* param_spec_gnonogram_permutor (const gchar* name, const gchar* nick, const gchar* blurb, GType object_type, GParamFlags flags);
void value_set_gnonogram_permutor (GValue* value, gpointer v_object);
void value_take_gnonogram_permutor (GValue* value, gpointer v_object);
gpointer value_get_gnonogram_permutor (const GValue* value);
GType gnonogram_permutor_get_type (void) G_GNUC_CONST;
GType cell_state_get_type (void) G_GNUC_CONST;
#define GNONOGRAM_PERMUTOR_GET_PRIVATE(o) (G_TYPE_INSTANCE_GET_PRIVATE ((o), TYPE_GNONOGRAM_PERMUTOR, Gnonogram_permutorPrivate))
enum  {
	GNONOGRAM_PERMUTOR_DUMMY_PROPERTY
};
Gnonogram_permutor* gnonogram_permutor_new (gint size, const gchar* clue);
Gnonogram_permutor* gnonogram_permutor_construct (GType object_type, gint size, const gchar* clue);
gint* utils_block_array_from_clue (const gchar* s, int* result_length1);
void gnonogram_permutor_initialise (Gnonogram_permutor* self);
gboolean gnonogram_permutor_next (Gnonogram_permutor* self);
static void gnonogram_permutor_make_perm (Gnonogram_permutor* self);
CellState* gnonogram_permutor_get (Gnonogram_permutor* self, int* result_length1);
static CellState* _vala_array_dup5 (CellState* self, int length);
gchar* gnonogram_permutor_to_string (Gnonogram_permutor* self);
static void gnonogram_permutor_finalize (Gnonogram_permutor* obj);


Gnonogram_permutor* gnonogram_permutor_construct (GType object_type, gint size, const gchar* clue) {
	Gnonogram_permutor* self = NULL;
	gint _tmp0_;
	gint* _tmp1_ = NULL;
	gint* _tmp2_;
	CellState* _tmp3_ = NULL;
	CellState* _tmp4_;
	gint extent;
	gint* _tmp5_ = NULL;
	gint* _tmp6_;
	gint* _tmp7_ = NULL;
	gint* _tmp8_;
	gint* _tmp9_ = NULL;
	gint* _tmp10_;
	g_return_val_if_fail (clue != NULL, NULL);
	self = (Gnonogram_permutor*) g_type_create_instance (object_type);
	self->priv->size = size;
	_tmp1_ = utils_block_array_from_clue (clue, &_tmp0_);
	_tmp2_ = _tmp1_;
	self->priv->blocks = (g_free (self->priv->blocks), NULL);
	self->priv->blocks_length1 = _tmp0_;
	self->priv->_blocks_size_ = self->priv->blocks_length1;
	self->priv->blocks = _tmp2_;
	_tmp3_ = g_new0 (CellState, size);
	_tmp4_ = _tmp3_;
	self->perm = (g_free (self->perm), NULL);
	self->perm_length1 = size;
	self->perm = _tmp4_;
	extent = 0;
	self->priv->n_blocks = self->priv->blocks_length1;
	_tmp5_ = g_new0 (gint, self->priv->n_blocks);
	_tmp6_ = _tmp5_;
	self->priv->range_start = (g_free (self->priv->range_start), NULL);
	self->priv->range_start_length1 = self->priv->n_blocks;
	self->priv->_range_start_size_ = self->priv->range_start_length1;
	self->priv->range_start = _tmp6_;
	_tmp7_ = g_new0 (gint, self->priv->n_blocks);
	_tmp8_ = _tmp7_;
	self->priv->range_end = (g_free (self->priv->range_end), NULL);
	self->priv->range_end_length1 = self->priv->n_blocks;
	self->priv->_range_end_size_ = self->priv->range_end_length1;
	self->priv->range_end = _tmp8_;
	_tmp9_ = g_new0 (gint, self->priv->n_blocks);
	_tmp10_ = _tmp9_;
	self->priv->block_start = (g_free (self->priv->block_start), NULL);
	self->priv->block_start_length1 = self->priv->n_blocks;
	self->priv->_block_start_size_ = self->priv->block_start_length1;
	self->priv->block_start = _tmp10_;
	{
		gint* b_collection;
		int b_collection_length1;
		int b_it;
		b_collection = self->priv->blocks;
		b_collection_length1 = self->priv->blocks_length1;
		for (b_it = 0; b_it < self->priv->blocks_length1; b_it = b_it + 1) {
			gint b;
			b = b_collection[b_it];
			{
				extent = extent + (b + 1);
			}
		}
	}
	extent--;
	self->priv->_freedom = size - extent;
	if (self->priv->_freedom < 0) {
		fprintf (stdout, "Invalid permutator\n");
	} else {
		self->valid = TRUE;
	}
	return self;
}


Gnonogram_permutor* gnonogram_permutor_new (gint size, const gchar* clue) {
	return gnonogram_permutor_construct (TYPE_GNONOGRAM_PERMUTOR, size, clue);
}


void gnonogram_permutor_initialise (Gnonogram_permutor* self) {
	gint start;
	g_return_if_fail (IS_GNONOGRAM_PERMUTOR (self));
	start = 0;
	{
		gint b;
		b = 0;
		{
			gboolean _tmp0_;
			_tmp0_ = TRUE;
			while (TRUE) {
				if (!_tmp0_) {
					b++;
				}
				_tmp0_ = FALSE;
				if (!(b < self->priv->n_blocks)) {
					break;
				}
				self->priv->range_start[b] = start;
				self->priv->block_start[b] = self->priv->range_start[b];
				self->priv->range_end[b] = start + self->priv->_freedom;
				start = start + (self->priv->blocks[b] + 1);
			}
		}
	}
	self->priv->block_start[self->priv->n_blocks - 1]--;
}


gboolean gnonogram_permutor_next (Gnonogram_permutor* self) {
	gboolean result = FALSE;
	g_return_val_if_fail (IS_GNONOGRAM_PERMUTOR (self), FALSE);
	{
		gint b;
		b = self->priv->n_blocks - 1;
		{
			gboolean _tmp0_;
			_tmp0_ = TRUE;
			while (TRUE) {
				if (!_tmp0_) {
					b--;
				}
				_tmp0_ = FALSE;
				if (!(b >= 0)) {
					break;
				}
				if (self->priv->block_start[b] == self->priv->range_end[b]) {
					if (self->priv->range_start[b] == self->priv->range_end[b]) {
						continue;
					} else {
						self->priv->range_start[b]++;
						self->priv->block_start[b] = self->priv->range_start[b];
					}
				} else {
					self->priv->block_start[b]++;
					gnonogram_permutor_make_perm (self);
					result = TRUE;
					return result;
				}
			}
		}
	}
	result = FALSE;
	return result;
}


static void gnonogram_permutor_make_perm (Gnonogram_permutor* self) {
	g_return_if_fail (IS_GNONOGRAM_PERMUTOR (self));
	{
		gint idx;
		idx = 0;
		{
			gboolean _tmp0_;
			_tmp0_ = TRUE;
			while (TRUE) {
				if (!_tmp0_) {
					idx++;
				}
				_tmp0_ = FALSE;
				if (!(idx < self->priv->size)) {
					break;
				}
				self->perm[idx] = CELL_STATE_EMPTY;
			}
		}
	}
	{
		gint b;
		b = 0;
		{
			gboolean _tmp1_;
			_tmp1_ = TRUE;
			while (TRUE) {
				if (!_tmp1_) {
					b++;
				}
				_tmp1_ = FALSE;
				if (!(b < self->priv->n_blocks)) {
					break;
				}
				{
					gint idx;
					idx = self->priv->block_start[b];
					{
						gboolean _tmp2_;
						_tmp2_ = TRUE;
						while (TRUE) {
							if (!_tmp2_) {
								idx++;
							}
							_tmp2_ = FALSE;
							if (!(idx < (self->priv->block_start[b] + self->priv->blocks[b]))) {
								break;
							}
							self->perm[idx] = CELL_STATE_FILLED;
						}
					}
				}
			}
		}
	}
}


static CellState* _vala_array_dup5 (CellState* self, int length) {
	return g_memdup (self, length * sizeof (CellState));
}


CellState* gnonogram_permutor_get (Gnonogram_permutor* self, int* result_length1) {
	CellState* result = NULL;
	CellState* _tmp0_;
	CellState* _tmp1_;
	CellState* _tmp2_;
	g_return_val_if_fail (IS_GNONOGRAM_PERMUTOR (self), NULL);
	_tmp0_ = (_tmp1_ = self->perm, (_tmp1_ == NULL) ? ((gpointer) _tmp1_) : _vala_array_dup5 (_tmp1_, self->perm_length1));
	_tmp2_ = _tmp0_;
	*result_length1 = self->perm_length1;
	result = _tmp2_;
	return result;
}


gchar* gnonogram_permutor_to_string (Gnonogram_permutor* self) {
	gchar* result = NULL;
	GString* _tmp0_ = NULL;
	GString* sb;
	gchar* _tmp3_;
	g_return_val_if_fail (IS_GNONOGRAM_PERMUTOR (self), NULL);
	_tmp0_ = g_string_new ("");
	sb = _tmp0_;
	{
		CellState* cs_collection;
		int cs_collection_length1;
		int cs_it;
		cs_collection = self->perm;
		cs_collection_length1 = self->perm_length1;
		for (cs_it = 0; cs_it < self->perm_length1; cs_it = cs_it + 1) {
			CellState cs;
			cs = cs_collection[cs_it];
			{
				gchar* _tmp1_ = NULL;
				gchar* _tmp2_;
				_tmp1_ = g_strdup_printf ("%i", (gint) cs);
				_tmp2_ = _tmp1_;
				g_string_append (sb, _tmp2_);
				_g_free0 (_tmp2_);
			}
		}
	}
	_tmp3_ = g_strdup (sb->str);
	result = _tmp3_;
	_g_string_free0 (sb);
	return result;
}


static void value_gnonogram_permutor_init (GValue* value) {
	value->data[0].v_pointer = NULL;
}


static void value_gnonogram_permutor_free_value (GValue* value) {
	if (value->data[0].v_pointer) {
		gnonogram_permutor_unref (value->data[0].v_pointer);
	}
}


static void value_gnonogram_permutor_copy_value (const GValue* src_value, GValue* dest_value) {
	if (src_value->data[0].v_pointer) {
		dest_value->data[0].v_pointer = gnonogram_permutor_ref (src_value->data[0].v_pointer);
	} else {
		dest_value->data[0].v_pointer = NULL;
	}
}


static gpointer value_gnonogram_permutor_peek_pointer (const GValue* value) {
	return value->data[0].v_pointer;
}


static gchar* value_gnonogram_permutor_collect_value (GValue* value, guint n_collect_values, GTypeCValue* collect_values, guint collect_flags) {
	if (collect_values[0].v_pointer) {
		Gnonogram_permutor* object;
		object = collect_values[0].v_pointer;
		if (object->parent_instance.g_class == NULL) {
			return g_strconcat ("invalid unclassed object pointer for value type `", G_VALUE_TYPE_NAME (value), "'", NULL);
		} else if (!g_value_type_compatible (G_TYPE_FROM_INSTANCE (object), G_VALUE_TYPE (value))) {
			return g_strconcat ("invalid object type `", g_type_name (G_TYPE_FROM_INSTANCE (object)), "' for value type `", G_VALUE_TYPE_NAME (value), "'", NULL);
		}
		value->data[0].v_pointer = gnonogram_permutor_ref (object);
	} else {
		value->data[0].v_pointer = NULL;
	}
	return NULL;
}


static gchar* value_gnonogram_permutor_lcopy_value (const GValue* value, guint n_collect_values, GTypeCValue* collect_values, guint collect_flags) {
	Gnonogram_permutor** object_p;
	object_p = collect_values[0].v_pointer;
	if (!object_p) {
		return g_strdup_printf ("value location for `%s' passed as NULL", G_VALUE_TYPE_NAME (value));
	}
	if (!value->data[0].v_pointer) {
		*object_p = NULL;
	} else if (collect_flags & G_VALUE_NOCOPY_CONTENTS) {
		*object_p = value->data[0].v_pointer;
	} else {
		*object_p = gnonogram_permutor_ref (value->data[0].v_pointer);
	}
	return NULL;
}


GParamSpec* param_spec_gnonogram_permutor (const gchar* name, const gchar* nick, const gchar* blurb, GType object_type, GParamFlags flags) {
	ParamSpecGnonogram_permutor* spec;
	g_return_val_if_fail (g_type_is_a (object_type, TYPE_GNONOGRAM_PERMUTOR), NULL);
	spec = g_param_spec_internal (G_TYPE_PARAM_OBJECT, name, nick, blurb, flags);
	G_PARAM_SPEC (spec)->value_type = object_type;
	return G_PARAM_SPEC (spec);
}


gpointer value_get_gnonogram_permutor (const GValue* value) {
	g_return_val_if_fail (G_TYPE_CHECK_VALUE_TYPE (value, TYPE_GNONOGRAM_PERMUTOR), NULL);
	return value->data[0].v_pointer;
}


void value_set_gnonogram_permutor (GValue* value, gpointer v_object) {
	Gnonogram_permutor* old;
	g_return_if_fail (G_TYPE_CHECK_VALUE_TYPE (value, TYPE_GNONOGRAM_PERMUTOR));
	old = value->data[0].v_pointer;
	if (v_object) {
		g_return_if_fail (G_TYPE_CHECK_INSTANCE_TYPE (v_object, TYPE_GNONOGRAM_PERMUTOR));
		g_return_if_fail (g_value_type_compatible (G_TYPE_FROM_INSTANCE (v_object), G_VALUE_TYPE (value)));
		value->data[0].v_pointer = v_object;
		gnonogram_permutor_ref (value->data[0].v_pointer);
	} else {
		value->data[0].v_pointer = NULL;
	}
	if (old) {
		gnonogram_permutor_unref (old);
	}
}


void value_take_gnonogram_permutor (GValue* value, gpointer v_object) {
	Gnonogram_permutor* old;
	g_return_if_fail (G_TYPE_CHECK_VALUE_TYPE (value, TYPE_GNONOGRAM_PERMUTOR));
	old = value->data[0].v_pointer;
	if (v_object) {
		g_return_if_fail (G_TYPE_CHECK_INSTANCE_TYPE (v_object, TYPE_GNONOGRAM_PERMUTOR));
		g_return_if_fail (g_value_type_compatible (G_TYPE_FROM_INSTANCE (v_object), G_VALUE_TYPE (value)));
		value->data[0].v_pointer = v_object;
	} else {
		value->data[0].v_pointer = NULL;
	}
	if (old) {
		gnonogram_permutor_unref (old);
	}
}


static void gnonogram_permutor_class_init (Gnonogram_permutorClass * klass) {
	gnonogram_permutor_parent_class = g_type_class_peek_parent (klass);
	GNONOGRAM_PERMUTOR_CLASS (klass)->finalize = gnonogram_permutor_finalize;
	g_type_class_add_private (klass, sizeof (Gnonogram_permutorPrivate));
}


static void gnonogram_permutor_instance_init (Gnonogram_permutor * self) {
	self->priv = GNONOGRAM_PERMUTOR_GET_PRIVATE (self);
	self->valid = FALSE;
	self->ref_count = 1;
}


static void gnonogram_permutor_finalize (Gnonogram_permutor* obj) {
	Gnonogram_permutor * self;
	self = GNONOGRAM_PERMUTOR (obj);
	self->priv->blocks = (g_free (self->priv->blocks), NULL);
	self->priv->range_start = (g_free (self->priv->range_start), NULL);
	self->priv->range_end = (g_free (self->priv->range_end), NULL);
	self->priv->block_start = (g_free (self->priv->block_start), NULL);
	self->perm = (g_free (self->perm), NULL);
}


GType gnonogram_permutor_get_type (void) {
	static volatile gsize gnonogram_permutor_type_id__volatile = 0;
	if (g_once_init_enter (&gnonogram_permutor_type_id__volatile)) {
		static const GTypeValueTable g_define_type_value_table = { value_gnonogram_permutor_init, value_gnonogram_permutor_free_value, value_gnonogram_permutor_copy_value, value_gnonogram_permutor_peek_pointer, "p", value_gnonogram_permutor_collect_value, "p", value_gnonogram_permutor_lcopy_value };
		static const GTypeInfo g_define_type_info = { sizeof (Gnonogram_permutorClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) gnonogram_permutor_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (Gnonogram_permutor), 0, (GInstanceInitFunc) gnonogram_permutor_instance_init, &g_define_type_value_table };
		static const GTypeFundamentalInfo g_define_type_fundamental_info = { (G_TYPE_FLAG_CLASSED | G_TYPE_FLAG_INSTANTIATABLE | G_TYPE_FLAG_DERIVABLE | G_TYPE_FLAG_DEEP_DERIVABLE) };
		GType gnonogram_permutor_type_id;
		gnonogram_permutor_type_id = g_type_register_fundamental (g_type_fundamental_next (), "Gnonogram_permutor", &g_define_type_info, &g_define_type_fundamental_info, 0);
		g_once_init_leave (&gnonogram_permutor_type_id__volatile, gnonogram_permutor_type_id);
	}
	return gnonogram_permutor_type_id__volatile;
}


gpointer gnonogram_permutor_ref (gpointer instance) {
	Gnonogram_permutor* self;
	self = instance;
	g_atomic_int_inc (&self->ref_count);
	return instance;
}


void gnonogram_permutor_unref (gpointer instance) {
	Gnonogram_permutor* self;
	self = instance;
	if (g_atomic_int_dec_and_test (&self->ref_count)) {
		GNONOGRAM_PERMUTOR_GET_CLASS (self)->finalize (self);
		g_type_free_instance ((GTypeInstance *) self);
	}
}



