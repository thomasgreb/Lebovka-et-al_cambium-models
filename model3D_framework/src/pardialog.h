/*
 *
 *  $Id$
 *
 *  This file is part of the Virtual Leaf.
 *
 *  VirtualLeaf is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  VirtualLeaf is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with the Virtual Leaf.  If not, see <http://www.gnu.org/licenses/>.
 *
 *  Copyright 2010 Roeland Merks.
 *
 */

// WARNING: This file is automatically generated by make_parameter_source.pl. Do not edit.
// Do not edit. All edits will be discarded.

#ifndef PARAMETER_DIALOG_H
#define PARAMETER_DIALOG_H
#include <qdialog.h>
#include <qspinbox.h>
#include <qlineedit.h>
#include <qlayout.h>
#include <qpushbutton.h>
#include <iostream>

class ParameterDialog : public QDialog {
    Q_OBJECT
	
      public:
	ParameterDialog(QWidget *parent=0, const char *name = 0, Qt::WindowFlags f = 0);
    virtual ~ParameterDialog(void);
    public slots:
    void Reset(void);

    private slots:
    void write(void);

  private:
  QLineEdit *arrowcolor_edit;
  QLineEdit *arrowlength_edit;
  QLineEdit *textcolor_edit;
  QLineEdit *cellnumsize_edit;
  QLineEdit *nodenumsize_edit;
  QLineEdit *node_mag_edit;
  QLineEdit *outlinewidth_edit;
  QLineEdit *cell_outline_color_edit;
  QLineEdit *resize_stride_edit;
  QLineEdit *datadir_edit;
  QLineEdit *export_fn_prefix_edit;
  QLineEdit *export_interval_edit;
  QLineEdit *xml_storage_stride_edit;
  QLineEdit *movie_edit;
  QLineEdit *storage_stride_edit;
  QLineEdit *dt_edit;
  QLineEdit *rd_dt_edit;
  QLineEdit *ode_accuracy_edit;
  QLineEdit *nit_edit;
  QLineEdit *maxt_edit;
  QLineEdit *rseed_edit;
  QLineEdit *T_edit;
  QLineEdit *lambda_length_edit;
  QLineEdit *mc_stepsize_edit;
  QLineEdit *collapse_node_threshold_edit;
  QLineEdit *yielding_threshold_edit;
  QLineEdit *rel_perimeter_stiffness_edit;
  QLineEdit *copy_wall_edit;
  QLineEdit *energy_threshold_edit;
  QLineEdit *mc_cell_stepsize_edit;
  QLineEdit *lambda_celllength_edit;
  QLineEdit *target_length_edit;
  QLineEdit *bend_lambda_edit;
  QLineEdit *alignment_lambda_edit;
  QLineEdit *D_edit;
  QLineEdit *initval_edit;
  QLineEdit *k1_edit;
  QLineEdit *k2_edit;
  QLineEdit *k3_edit;
  QLineEdit *k4_edit;
  QLineEdit *k5_edit;
  QLineEdit *k6_edit;
  QLineEdit *k7_edit;
  QLineEdit *k8_edit;
  QLineEdit *k9_edit;
  QLineEdit *k10_edit;
  QLineEdit *wk1_edit;
  QLineEdit *wk2_edit;
  QLineEdit *wk3_edit;
  QLineEdit *wk4_edit;
  QLineEdit *wk5_edit;
  QLineEdit *wk6_edit;
  QLineEdit *wk7_edit;
  QLineEdit *wk8_edit;
  QLineEdit *wk9_edit;
  QLineEdit *wk10_edit;
};
#endif
