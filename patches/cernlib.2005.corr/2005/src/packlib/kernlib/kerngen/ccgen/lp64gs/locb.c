/*>    ROUTINE LOCB
  CERN PROGLIB# N101    LOCB            .VERSION KERNFOR  4.36  930602
*/

unsigned int chkloc(char *address);

unsigned int locb_(iadr)
   char *iadr;
{
   return (chkloc(iadr));
}

