/*
 *
 *  $Id: parse.h,v 15d600891648 2010/06/24 13:22:58 michael $
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


#ifndef _PARSE_H_
#define _PARSE_H_

char *ParsePar(FILE *fp, char *parameter, bool wrapflag);
int igetpar(FILE *fp,char *parameter, bool wrapflag);
int igetpar(FILE *fp,char *parameter, int default_val, bool wrapflag);
float fgetpar(FILE *fp,char *parameter, bool wrapflag);
float fgetpar(FILE *fp,char *parameter, double default_val, bool wrapflag);

/* Get a list of n comma separated doubles */
double *dgetparlist(FILE *fp,char *parameter, int n, bool wrapflag);
char *sgetpar(FILE *fp,char *parameter, bool wrapflag);
char *sgetpar(FILE *fp,char *parameter,const char *default_val, bool wrapflag);
bool bgetpar(FILE *fp, char *parameter, bool wrapflag);
bool bgetpar(FILE *fp, char *parameter, int default_val, bool wrapflag);
char *SearchToken(FILE *fp, char *token, bool wrapflag);
int TokenInLineP(char *line,char *token);
void SkipToken(FILE *fp,char *token, bool wrapflag);
void SkipLine(FILE *fp);
char *bool_str(bool bool_var);

#endif

/* finis */
