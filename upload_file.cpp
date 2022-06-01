 /* -*-mode:c++; c-file-style: "gnu";-*- */
 /*
  *  $Id: upload_8cpp-source.html,v 1.3 2008/01/19 21:53:50 sebdiaz Exp $
  *
  *  Copyright (C) 1996 - 2004 Stephen F. Booth <sbooth@gnu.org>
  *                       2007 Sebastien DIAZ <sebastien.diaz@gmail.com>
  *  Part of the GNU cgicc library, http://www.gnu.org/software/cgicc
  *
  *  This library is free software; you can redistribute it and/or
  *  modify it under the terms of the GNU Lesser General Public
  *  License as published by the Free Software Foundation; either
  *  version 3 of the License, or (at your option) any later version.
  *
  *  This library is distributed in the hope that it will be useful,
  *  but WITHOUT ANY WARRANTY; without even the implied warranty of
  *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  *  Lesser General Public License for more details.
  *
  *  You should have received a copy of the GNU Lesser General Public
  *  License along with this library; if not, write to the Free Software
  *  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110, USA 
  */
 
 #include <iostream>
 #include <fstream>

 #include "cgicc/CgiDefs.h"
 #include "cgicc/Cgicc.h"
 #include "cgicc/HTTPHTMLHeader.h"
 #include "cgicc/HTMLClasses.h"

using namespace cgicc;

int main(int /*argc*/, char ** /*argv*/)
{
    std::cout << "Content-Type:text/plain;charset=utf-8\n\n";

    // Create a new Cgicc object containing all the CGI data
    Cgicc cgi;
    
    // Obtiene el archivo que fue enviado mendiante el formulario.
    const_file_iterator file = cgi.getFile(".pdf");

    //Creo un archivo con el nombre del mismo...
    std::ofstream saveFile("./uploaded_files/" + file->getFilename());
    file->writeToStream(saveFile);
    saveFile.close();    
 
     return EXIT_SUCCESS;
 }
