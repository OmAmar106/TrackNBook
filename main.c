#include<stdio.h>
#include<string.h>
int N = 20;
char locations[20][20] = {"Butibori","IIITN","Airport Metro"};
int arr[10][10];
void print(char arr[N][20]){
    printf("\n");
    for(int i=0;i<N;i++){
        printf("%d. %s\n",i+1,arr[i]);
    }
}
int main(){
    printf(" ________  _______        _       ______  _   __    _  _     ___     ______     _____      _____     _  __\n");
    printf("'   ||   '||      |     // \\   //       \\ || //      || \\     ||     ||     \\  //     \\   //     \\   || //\n");
    printf("    ||    ||      |    //   \\  ||         ||//       ||   \\   ||     ||     || ||     ||  ||     ||  ||//\n");
    printf("    ||    || ____/    //_____\\ ||         ||\\     _  ||    \\  ||  _  ||_____/  ||     ||  ||     ||  ||\\\n");
    printf("    ||    ||      \\  //       \\ \\         || \\       ||     \\ ||     ||     || ||     ||  ||     ||  || \\ \n");
    printf("   _||_   ||       \\//         \\ \\______/_||_ \\__   _||_     _||_    ||_____/   \\____//    \\____//  _||_ \\__\n");
    printf("___________________________________________________________________________________________________________\n");
    //History check krne ke liye ek kam krna naam ke sath save krna , isse log in ka kuch toh use ajayega
    //make a array of string with places within nagpur and make a adjency matrix 
    //set ditance and use arr as an adjacency matrix 
    while(1){
        printf("\n1. Sign Up\n");
        printf("2. Log In\n");
        printf("3. Exit\n\n");
        printf("Enter Choice : ");
        int choice;
        scanf("%d",&choice);
        printf("\n");
        if(choice==1){
            char username[100];
            char password1[100];
            char password2[100];
            printf("Enter UserName(without space) : ");
            scanf("%s",username);
            printf("Enter Password : ");
            scanf("%s",password1);
            printf("Enter Password Again : ");
            scanf("%s",password2);
            int exist = 0;
            //if i find the username already in the notepad file , make exist 1
            if(strcmp(password1, password2) == 0 && exist!=1){
                printf("\nSign in now\n");
            }
            else{
                printf("\nUser already exists or password does not match, Try again.\n");
            }
        }
        else if(choice==2){
            char username[100];
            char password1[100];
            printf("Enter username(without space) : ");
            scanf("%s",username);
            printf("Enter Password : ");
            scanf("%s",password1);
            //check if these are in notepad or not
            int exist = 0;
            if(exist!=1){
                int choice1 = 0;
                while(choice1!=6){
                    printf("\nWelcome %s",username);
                    printf("\n\nWhat would you like to do today?");
                    printf("\n1. Book a Cab");
                    printf("\n2. Book a Bus");
                    printf("\n3. Shortest Path Calculator");
                    printf("\n4. Fare Calculator");
                    printf("\n5. Veiw last Booking");
                    printf("\n6. Log out");
                    printf("\nEnter choice : ");
                    scanf("%d",&choice1);
                    //shortest path calculator mai dijikistra algo lagane 
                    //aur options ke bade soche asap
                    if(choice1==1){
                        continue;
                    }
                    else if(choice1==4){
                        int startpoint;
                        print(locations);
                        printf("\nEnter Start Point : ");
                        scanf("%d",&startpoint);
                        int endpoint;
                        printf("\nEnter End Point : ");        
                        scanf("%d",&endpoint);
                        //print types of mode
                        printf("\nEnter mode : ");
                        //perform dijikistras algo then multiply depending upon the type of mode
                    }
                    else if(choice1==6){
                        break;
                    }
                    else{
                        printf("\nPlease enter from 1 to 6\n");
                    }
                }
            }
            else{
                printf("\nWrong Username or Password please enter again.");
            }
            printf("\n");
        }
        else if(choice==3){
            printf("Thank You\n");
            break;
        }
        else{
            printf("Enter Choice from 1-3\n");
        }
    }
}