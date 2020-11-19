//*********************************************************
//
// Mariah Roberts
// Operating Systems
// Project #1: New Island Shell - Writing Your Own Shell
//
//*********************************************************


//*********************************************************
//
// Includes and Defines
//
//*********************************************************
#include <iostream>
#include <unistd.h>
#include <sys/types.h>
#include <errno.h>
#include <signal.h>
#include <string.h>
#include <cstdlib>


using namespace std;


//*********************************************************
//
// Extern Declarations
//
//*********************************************************
using namespace std;
extern "C"
{
  extern char **gettoks();
} 

//*********************************************************
//
// Main Function
//
//*********************************************************
int main( int argc, char *argv[] )
{
  // local variables
  int ii;
  char **toks;
  int retval;

  // initialize local variables
  ii = 0;
  toks = NULL;
  retval = 0;

  // main (infinite) loop
  while( true )
    {
      // get arguments
      toks = gettoks();

      if( toks[0] != NULL )
	{
	  // simple loop to echo all arguments
	  for( ii=0; toks[ii] != NULL; ii++ )
	    {
	      cout << "Argument " << ii << ": " << toks[ii] << endl;
	    }

	  if( !strcmp( toks[0], "exit" ))
	    break;
	}
    }

  // return to calling environment
  return( retval );
}