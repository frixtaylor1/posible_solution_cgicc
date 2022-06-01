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
