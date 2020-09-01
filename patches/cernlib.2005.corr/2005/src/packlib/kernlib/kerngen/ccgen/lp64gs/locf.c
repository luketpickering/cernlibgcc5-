/*>    ROUTINE LOCF
  CERN PROGLIB# N100    LOCF            .VERSION KERNFOR  4.36  930602
*/
unsigned int chkloc(char *address);

unsigned int locf_(iadr)
   char *iadr;
{
   return ( (chkloc(iadr)) >> 2 );
}
