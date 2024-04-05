#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>
#include<limits.h>
#define N 20
char locations[N][20] = {"Butibori","IIIT Nagpur","Airport Metro"};
int arr[N][N];
struct node{
    char name[50];
    struct node* next;
    struct node* prev;
};
//add all the orange line and aqua line stations to the struct and then traverse through it 
void printLL(struct node* head){
    int i = 0;
    while(head!=NULL){
        printf("\n%d. %s",i+1,head->name);
        head = head->next;
        i++;
    }
}
void print(char arr[N][20]){
    for(int i=0;i<N;i++){
        printf("\n%d. %s",i+1,arr[i]);
    }
}
struct node* createnode(char name[]){
    struct node* new;
    new=(struct node*)malloc(sizeof(struct node));
    strcpy(new->name,name);
    new->next=NULL;
    new->prev=NULL;
    return new;
}
int minDistance(int dist[], bool sptSet[])
{
    int min = INT_MAX, min_index;
    for (int v = 0; v < N; v++)
        if (sptSet[v] == false && dist[v] <= min)
            min = dist[v], min_index = v;
    return min_index;
}
void printSolution(int dist[],int dest,int src)
{
    printf("\nDistance from %s to %s is %d\n",locations[src],locations[dest],dist[dest]);
}
void dijkstra(int graph[N][N], int src,int dest)
{
    int dist[N]; 
    bool sptSet[N];
    for (int i = 0; i < N; i++)
        dist[i] = INT_MAX, sptSet[i] = false;
    dist[src] = 0;
    for (int count = 0; count < N - 1; count++) {
        int u = minDistance(dist, sptSet);
        sptSet[u] = true;
        for (int v = 0; v < N; v++)
            if (!sptSet[v] && graph[u][v]
                && dist[u] != INT_MAX
                && dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
    }
    printSolution(dist,dest,src);
}
struct node* add(struct node*head,char name[])
{
    struct node*newstation=createnode(name);
    if(head==NULL)
    {
        return newstation;
    }
    struct node*temp=head;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=newstation;
    newstation->prev=temp;
    return head;
}
struct node* aqua(){
    struct node*head=NULL;
    head=add(head,"PRAJAPATI NAGAR");
    head=add(head,"VAISHNODEVI SQUARE");
    head=add(head,"AMBEDKAR SQUARE");
    head=add(head,"TELEPHONE EXCHANGE");
    head=add(head,"CHITAROLI SQUARE");
    head=add(head,"AGRASEN SQUARE");
    head=add(head,"DOSAR VAISHYA SQUARE");
    head=add(head,"NAGPUR RAILWAY STATION");
    head=add(head,"COTTON MARKET");
    head=add(head,"SITABULDI");
    head=add(head,"JHANSI RANI SQUARE");
    head=add(head,"INSTITUTE OF ENGINEERS");
    head=add(head,"SHANKAR NAGAR SQUARE");
    head=add(head,"L.A.D. COLLLEGE SQUARE");
    head=add(head,"AMBAZARI LAKE");
    head=add(head,"SUBHASH NAGAR");
    head=add(head,"RACHANA RING ROAD JUNCTION");
    head=add(head,"VASUDEV NAGAR");
    head=add(head,"BANSI NAGAR");
    head=add(head,"LOKMANYA NAGAR");
    return head;
}
struct node*orange(){
    struct node*head=NULL;
    head=add(head,"AUTOMATIVE SQUARE");
    head=add(head,"NARI ROAD");
    head=add(head,"INDORA SQUARE");
    head=add(head,"KADVI SQUARE");
    head=add(head,"GADDI GODAM SQUARE");
    head=add(head,"KASTURCHAND PARK");
    head=add(head,"ZERO MILE");
    head=add(head,"SITABULDI");
    head=add(head,"CONGRESS NAGAR");
    head=add(head,"RAHATE COLONY");
    head=add(head,"AJNI SQUARE");
    head=add(head,"CHHATRAPATI SQUARE");
    head=add(head,"JAIPRAKASH NAGAR");
    head=add(head,"UJJWAL NAGAR");
    head=add(head,"AIRPORT");
    head=add(head,"AIRPORT SOUTH");
    head=add(head,"NEW AIRPORT");
    head=add(head,"KHAPRI");
    return head;
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
                    printf("\n3. Book a Metro");
                    printf("\n4. Shortest Path Calculator");
                    printf("\n5. Veiw last Booking");
                    printf("\n6. Log out");
                    printf("\n\nEnter choice : ");
                    scanf("%d",&choice1);
                    //shortest path calculator mai dijikistra algo lagane 
                    //aur options ke bade soche asap
                    if(choice1==1){
                        continue;
                    }
                    else if(choice1==3){
                        struct node* AquaHead = aqua();
                        struct node* OrangeHead = orange();
                        printf("\nStart Point : ");
                        printf("\n1. Aqua Line");
                        printf("\n2. Orange Line");
                        printf("\nEnter Choice : ");
                        int line;
                        scanf("%d",&line);
                        int line1st = -1;
                        int line2st = -1;
                        if(line==1){
                            printLL(AquaHead);
                            printf("\nEnter Choice : ");
                            scanf("%d",&line1st);
                        }
                        else{
                            printLL(OrangeHead);
                            printf("\nEnter Choice : ");
                            scanf("%d",&line2st);
                        }
                        printf("\nEnd Point : ");
                        printf("\n1. Aqua Line");
                        printf("\n2. Orange Line");
                        printf("\nEnter Choice : ");
                        scanf("%d",&line);
                        int line1ed = -1;
                        int line2ed = -1;
                        if(line==1){
                            printLL(AquaHead);
                            printf("\nEnter Choice : ");
                            scanf("%d",&line1ed);
                        }
                        else{
                            printLL(OrangeHead);
                            printf("\nEnter Choice : ");
                            scanf("%d",&line2ed);
                        }
                        if(line1ed!=-1 && line1st!=-1){
                            printf("\nThe cost is : %d",5*(abs(line1ed-line1st)));
                            printf("\nNumber of station you will be passing: %d",(abs(line1ed-line1st)));
                            //add confirmation to book the ticket 
                        }
                        else if(line2ed!=-1 && line2st!=-1){
                            printf("\nThe cost is : %d",5*(abs(line2ed-line2st)));
                            printf("\nNumber of station you will be passing: %d",(abs(line2ed-line2st)));
                        }
                        else if(line2st==-1 && line1ed==-1){
                            printf("\nThe cost is : %d",5*(abs(line2ed-8)+abs(10-line1st)));
                            printf("\nNumber of station you will be passing: %d",(abs(line2ed-8)+abs(10-line1st)));
                        }
                        else{
                            printf("\nThe cost is : %d",5*(abs(line1ed-10)+abs(8-line2st)));
                            printf("\nNumber of station you will be passing: %d",(abs(line1ed-10)+abs(8-line2st)));
                        }
                        printf("\n");
                    }
                    else if(choice1==4){
                        int startpoint;
                        print(locations);
                        printf("\nEnter Start Point : ");
                        scanf("%d",&startpoint);
                        int endpoint;
                        printf("\nEnter End Point : ");        
                        scanf("%d",&endpoint);
                        //apply algo here
                        dijkstra(arr,startpoint-1,endpoint-1);
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