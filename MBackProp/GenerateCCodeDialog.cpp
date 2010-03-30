/*
	Noel Lopes is an Assistant Professor at the Polytechnic Institute of Guarda, Portugal (for more information see readme.txt)
    Copyright (C) 1999, 2000, 2001, 2002, 2003, 2004, 2005, 2006, 2007, 2008, 2009, 2010 Noel de Jesus Mendon�a Lopes

	This file is part of Multiple Back-Propagation.

    Multiple Back-Propagation is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

/**
 Class    : GenerateCCodeDialog
 Puropse  : Generate C code dialog class.
 Author   : Noel de Jesus Mendon�a Lopes
 Date     : 26 of December of 1999
 Reviewed : Never
 Version  : 1.0.0
 Comments :
             ---------
            | CObject |
             ---------
                |   ------------
                -->| CCmdTarget |
                    ------------
                      |   ------
                      -->| CWnd |
                          ------
                            |   ---------
                            -->| CDialog |
                                ---------
                                  |   ----------------
                                  -->| LoadSaveDialog |
                                      ----------------
                                        |   ---------------------
                                        -->| GenerateCCodeDialog |
                                            ---------------------
*/
#include "stdafx.h"
#include "MBackProp.h"
#include "GenerateCCodeDialog.h"

#ifdef _DEBUG
	#define new DEBUG_NEW
	#undef THIS_FILE
	static char THIS_FILE[] = __FILE__;
#endif

/**
 Method  : void GenerateCCodeDialog::OnOK()
 Purpose : Write C code corresponding to the actual feed forward network.
 Version : 1.0.0
*/
void GenerateCCodeDialog::OnOK() {
	CString filename = filenameBox.GetFileName();

	if (filename.IsEmpty()) {
		WarnUser(_TEXT("You must specify the filename where to save the generated C code."), _TEXT("Invalid file"));
		filenameBox.SetFocus();
	} else {
		if (parent->GenerateCCode(filenameBox.GetFileName())) LoadSaveDialog::OnOK();
	}
}