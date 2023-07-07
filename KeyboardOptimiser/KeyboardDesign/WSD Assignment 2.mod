/*********************************************
 * OPL 22.1.1.0 Model
 * Author: biswa
 * Creation Date: 28-Mar-2023 at 9:51:33 PM
 *********************************************/
int n =...;
range r = 1..n;

float probability[r][r]=...;
float milliseconds[r][r]=...;


dvar boolean x[r][r];



minimize 
     sum(i in r ,j in r,l in r,k in r) probability[k][l]*milliseconds[i][j]*x[j][l]*x[i][k];


subject to
{
  forall(i in r) sum(j in r) x[i][j] == 1;
  forall(j in r) sum(i in r) x[i][j] == 1;
 }   