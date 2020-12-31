/*-
 * Copyright (c) 2004-2006 Benedikt Meurer <benny@xfce.org>
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Library General Public
 * License as published by the Free Software Foundation; either
 * version 3 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Library General Public License for more details.
 *
 * You should have received a copy of the GNU Library General Public
 * License along with this library; if not, write to the
 * Free Software Foundation, Inc., 59 Temple Place - Suite 330,
 * Boston, MA 02111-1307, USA.
 */

/* Modified by Hong Jen Yee (PCMan) <pcman.tw@gmail.com>
 * on 2008.07.13 for use in PCManFM */

#ifndef __EXO_TREE_VIEW_H__
#define __EXO_TREE_VIEW_H__

#include <stdbool.h>

#include <gtk/gtk.h>

G_BEGIN_DECLS

typedef struct ExoTreeViewPrivate ExoTreeViewPrivate;

// clang-format off
#define EXO_TYPE_TREE_VIEW            (exo_tree_view_get_type ())
#define EXO_TREE_VIEW(obj)            (G_TYPE_CHECK_INSTANCE_CAST ((obj), EXO_TYPE_TREE_VIEW, ExoTreeView))
#define EXO_TREE_VIEW_CLASS(klass)    (G_TYPE_CHECK_CLASS_CAST ((klass), EXO_TYPE_TREE_VIEW, ExoTreeViewClass))
#define EXO_IS_TREE_VIEW(obj)         (G_TYPE_CHECK_INSTANCE_TYPE ((obj), EXO_TYPE_TREE_VIEW))
#define EXO_IS_TREE_VIEW_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), EXO_TYPE_TREE_VIEW))
#define EXO_TREE_VIEW_GET_CLASS(obj)  (G_TYPE_INSTANCE_GET_CLASS ((obj), EXO_TYPE_TREE_VIEW, ExoTreeViewClass))
// clang-format on

typedef struct ExoTreeViewClass
{
    /*< private >*/
    GtkTreeViewClass __parent__;

    /*< private >*/
    void (*reserved1)(void);
    void (*reserved2)(void);
    void (*reserved3)(void);
    void (*reserved4)(void);
    void (*reserved5)(void);
    void (*reserved6)(void);
    void (*reserved7)(void);
    void (*reserved8)(void);
} ExoTreeViewClass;

/**
 * ExoTreeView:
 *
 * The #ExoIconView struct contains only private fields and should
 * not be directly accessed.
 **/
typedef struct ExoTreeView
{
    /*< private >*/
    GtkTreeView __parent__;

    /*< private >*/
    ExoTreeViewPrivate* priv;
} ExoTreeView;

GType exo_tree_view_get_type(void) G_GNUC_CONST;

GtkWidget* exo_tree_view_new(void) G_GNUC_MALLOC;

bool exo_tree_view_get_single_click(const ExoTreeView* tree_view);
void exo_tree_view_set_single_click(ExoTreeView* tree_view, bool single_click);

unsigned int exo_tree_view_get_single_click_timeout(const ExoTreeView* tree_view);
void exo_tree_view_set_single_click_timeout(ExoTreeView* tree_view,
                                            unsigned int single_click_timeout);

/* 2008.07.16 added by Hong Jen Yee for PCManFM.
 * If activable column is set, only the specified column can be activated.
 * Other columns are viewed as blank area and won't receive mouse clicks.
 */
GtkTreeViewColumn* exo_tree_view_get_activable_column(ExoTreeView* tree_view);
void exo_tree_view_set_activable_column(ExoTreeView* tree_view, GtkTreeViewColumn* column);

G_END_DECLS

#endif /* !__EXO_TREE_VIEW_H__ */
