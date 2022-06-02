/* This file is an image processing operation for GEGL
 *
 * GEGL is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 3 of the License, or (at your option) any later version.
 *
 * GEGL is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with GEGL; if not, see <https://www.gnu.org/licenses/>.
 *
 * Copyright 2006 Øyvind Kolås <pippin@gimp.org>
 * 2022 Beaver Color fill Trail
 */

#include "config.h"
#include <glib/gi18n-lib.h>

#ifdef GEGL_PROPERTIES

property_double (x, _("X"), 95.0)
  description   (_("Horizontal shadow offset"))
  ui_range      (-300, 300.0)
  ui_steps      (1, 10)
  ui_meta       ("unit", "pixel-distance")
  ui_meta       ("axis", "x")

property_double (y, _("Y"), 28.0)
  description   (_("Vertical shadow offset"))
  ui_range      (-300.0, 300.0)
  ui_steps      (1, 10)
  ui_meta       ("unit", "pixel-distance")
  ui_meta       ("axis", "y")

property_color  (color, _("Color"), "#fd0002")


property_color  (color2, _("Color2"), "#fe7e00")

property_color  (color3, _("Color3"), "#ffff01")

property_color  (color4, _("Color4"), "#00fe01")

property_color  (color5, _("Color5"), "#00feff")



#else

#define GEGL_OP_META
#define GEGL_OP_NAME     ctrail
#define GEGL_OP_C_SOURCE ctrail.c

#include "gegl-op.h"

static void attach (GeglOperation *operation)
{
  GeglNode *gegl = operation->node;
  GeglNode *input, *output, *f1, *f2, *f3, *f4, *f5, *median;

  input    = gegl_node_get_input_proxy (gegl, "input");
  output   = gegl_node_get_output_proxy (gegl, "output");

  f1    = gegl_node_new_child (gegl,
                                  "operation", "gegl:zzfill",
                                  NULL);

  f2    = gegl_node_new_child (gegl,
                                  "operation", "gegl:zzfill",
                                  NULL);

  f3    = gegl_node_new_child (gegl,
                                  "operation", "gegl:zzfill",
                                  NULL);

  f4    = gegl_node_new_child (gegl,
                                  "operation", "gegl:zzfill",
                                  NULL);

  f5    = gegl_node_new_child (gegl,
                                  "operation", "gegl:zzfill",
                                  NULL);



  median    = gegl_node_new_child (gegl,
                                  "operation", "gegl:zzzmedian",
                                  NULL);







  gegl_node_link_many (input, f1, f2, f3, f4, f5, median, output, NULL);

  gegl_operation_meta_redirect (operation, "color", f1, "color");
  gegl_operation_meta_redirect (operation, "color2", f2, "color");
  gegl_operation_meta_redirect (operation, "color3", f3, "color");
  gegl_operation_meta_redirect (operation, "color4", f4, "color");
  gegl_operation_meta_redirect (operation, "color5", f5, "color");
  gegl_operation_meta_redirect (operation, "x", f1, "x");
  gegl_operation_meta_redirect (operation, "x", f2, "x");
  gegl_operation_meta_redirect (operation, "x", f3, "x");
  gegl_operation_meta_redirect (operation, "x", f4, "x");
  gegl_operation_meta_redirect (operation, "x", f5, "x");

  gegl_operation_meta_redirect (operation, "y", f1, "y");
  gegl_operation_meta_redirect (operation, "y", f2, "y");
  gegl_operation_meta_redirect (operation, "y", f3, "y");
  gegl_operation_meta_redirect (operation, "y", f4, "y");
  gegl_operation_meta_redirect (operation, "y", f5, "y");


}

static void
gegl_op_class_init (GeglOpClass *klass)
{
  GeglOperationClass *operation_class;

  operation_class = GEGL_OPERATION_CLASS (klass);

  operation_class->attach = attach;

  gegl_operation_class_set_keys (operation_class,
    "name",        "gegl:color-trail",
    "title",       _("Color Fill Trail"),
    "categories",  "Artistic",
    "reference-hash", "41ag1g3b0221aavx65493xc254001b2ac",
    "description", _("Make a color fill trail using GEGL. Use behind blend mode or make a back up layer. Setting a layer to transparency hides it. "
                     ""),
    NULL);
}

#endif
