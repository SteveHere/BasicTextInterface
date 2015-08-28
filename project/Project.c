//TODO: 
//- Add a method to login to the Interface
//  - Set up inputs for Username and Password
//  - Use bcrypt to hash password
//  - Store them in a file
//  - Find a way to protect the file
//

#include "Environment.c"

int main(void){
   char login;
   while(login!='N'){
      printf("Do you want to login(Y) or exit(N)? ");
      login = Input();
      if(login=='Y'){ Environment();} //modify parameter once login method has been set up
      else{
         //puts("Incorrect username or password. Try again."); //only use when login method is complete
         
         }
   }
   return 0;
}