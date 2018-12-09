//funciones clase agenda
#include "agenda.hpp"

/*
void Agenda::cargarDatosFichero(std::string nombre) //carga los datos de los alumnos al sistema desde un fichero binario
{
  std::ifstream f;
  f.open(nombre, std::ios::binary);
  if(!f.is_open())
  {
    std::cout<<"El fichero no se pudo abrir"<<\n;
  }
  else
  {
    //creo qeu se deberia de crear objeto alumno para poder meterlño en el vector
    //std::vector<Alumno> vAlumnos(std::istreambuf_iterator<char>(f), {});
    for(int i=0; i<vAlumnos.size(); i++)
    {
      std::ios::f>>"Alumno">>\n>>vAlumnos[i].getDni()>>\n;
      std::ios::f>>vAlumnos[i].getNombre()>>\n;
      std::ios::f>>vAlumnos[i].getApellidos()>>\n;
      std::ios::f>>vAlumnos[i].getTelefono()>>\n;
      std::ios::f>>vAlumnos[i].getFechaNacimiento()>>\n;
      std::ios::f>>vAlumnos[i].getEmail()>>\n;
      std::ios::f>>vAlumnos[i].getCurso()>>\n;
      std::ios::f>>vAlumnos[i].getGrupo()>>\n;
      std::ios::f>>vAlumnos[i].getLider()>>\n;
    }
  }
  f.close();
} */


void Agenda::guardarDatosFichero(std::string nombre) //carga los datos de los alumnos al sistema desde un fichero binario
{
  std::ofstream f;
  f.open(nombre, std::ios::binary);
  f.write((char *)&vAlumnos, vAlumnos.size());
    //std::vector<Alumno> vAlumnos(std::istreambuf_iterator<char>(f), {});
    /*for(int i=0; i<vAlumnos.size(); i++)
    {
      f << "Alumno " << i+1 << ": " << vAlumnos[i].getDni() << "," << vAlumnos[i].getNombre() << "," << vAlumnos[i].getApellidos() << "," << vAlumnos[i].getTelefono()
      << "," << vAlumnos[i].getFechaNacimiento() << "," << vAlumnos[i].getEmail() << "," << vAlumnos[i].getCurso() << "," << vAlumnos[i].getGrupo() << "," << vAlumnos[i].getLider()
      << "\n";
    }*/
  f.close();
}

bool Agenda::isLider(std::string dni)//comprueba si un alumno indicado por su dni es lider o no
{
  for(int i=0; i<vAlumnos.size(); i++)
  {
    if(vAlumnos[i].getDni() == dni)
    {
      if(vAlumnos[i].getLider() == 1)
      {
        return true;
      }
    }
  }
  return false;
}

void Agenda::mostrarAlumnosTerminal() //muestra la lista de alumnos con todos sus datos por la terminal
{
  if(vAlumnos.empty())
  {
    std::cout<<"La agenda de alumnos está vacía\n";
  } else{
    for(int i=0; i<vAlumnos.size(); i++)
    {
      std::cout<< "Alumno "<<i+1<<": \n";
      std::cout<<"DNI: " << vAlumnos[i].getDni() << "\n";
      std::cout<<"Nombre: " << vAlumnos[i].getNombre() << "\n";
      std::cout<<"Apellidos: " << vAlumnos[i].getApellidos() << "\n";
      std::cout<<"Telefono: " << vAlumnos[i].getTelefono() << "\n";
      std::cout<<"Fecha de Nacimiento: " << vAlumnos[i].getFechaNacimiento() << "\n";
      std::cout<<"Email: " << vAlumnos[i].getEmail() << "\n";
      std::cout<<"Curso: " << vAlumnos[i].getCurso() << "\n";
      std::cout<<"Grupo: " << vAlumnos[i].getGrupo() << "\n";

      if( isLider(vAlumnos[i].getDni()) == true )
      {
        std::cout<<"El alumno es lider\n";
      } else{
        std::cout<<"El alumno no es lider\n";
      }
    }
  }
}

void Agenda::mostrarAlumnosHTML() //genera un fichero HTML "alumnos.html" con los datos de todos los alumnos.
{
  if(vAlumnos.empty())
  {
    std::cout<<"La agenda de alumnos está vacía\n";
  } else{
    std::ofstream myfile;
    std::string es_lider;
    myfile.open("alumno.html");
    myfile << "<html> <body> <h2>Lista de Alumnos:</h2> <table border=3> <head> <td><b>Alumno</b></td> <td><b>DNI</b></td> <td><b>Nombre</b></td> <td><b>Apellidos</b></td> <td><b>Telefono</b></td> <td><b>Fecha de Nacimiento</b></td> <td><b>Email</b></td> <td><b>Curso</b></td> <td><b>Grupo</b></td> <td><b>Lider</b></td> </head>";
    for (int i = 0; i<vAlumnos.size(); i++)
    {
      myfile << "<tr>";
      if( isLider(vAlumnos[i].getDni()) == true )
      {
        es_lider = "Sí";
      } else{
        es_lider = "No";
      }

      myfile << "<td> "<< i+1 << "</td><td>" << vAlumnos[i].getDni()  << "</td><td>" << vAlumnos[i].getNombre() << "</td><td>" << vAlumnos[i].getApellidos() << "</td><td>" << vAlumnos[i].getTelefono()
      << "</td><td>" << vAlumnos[i].getFechaNacimiento() << "</td><td>" << vAlumnos[i].getEmail() << "</td><td>" << vAlumnos[i].getCurso() << "</td><td>" << vAlumnos[i].getGrupo()
      << "</td><td>" << es_lider << "</td>";
      myfile << "</tr>";
    }

    myfile << "</table></body></html>";
    myfile.close();
  }
}

int Agenda::searchAlumnoDNI(std::string dni) //devuelve la posicion del alumno que se está buscando
{
  for(int i=0; i<vAlumnos.size(); i++)
  {
    if(vAlumnos[i].getDni().compare(dni) == 0)
    {
      return i;
    }
  }
  return 0;
}


bool Agenda::addAlumno(Alumno alumno)
{
  if(vAlumnos.size() < 150){ //SI en la clase hay menos de 150 alumnos, se puede añadir un alumno
      vAlumnos.push_back(alumno);
      return true;
  }
  return false;
}

bool Agenda::deleteAlumno(std::string dni)//EL metodo debe borrar por dni
{
  if(!vAlumnos.empty())
  {
    int numDni = searchAlumnoDNI(dni);
    vAlumnos.erase(vAlumnos.begin()+numDni);
    return true;
  }
  return false;
}