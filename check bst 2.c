#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#define NEW 12
#define OLD 13
#define PRINT 14
#define SEARCH_F_NAME 15
#define SEARCH_L_NAME 16
#define OCC_BG 17
#define OCC_AOR 18
#define SEX_OCC 19
#define BG_AOR 20
#define SEX_BG 21
#define SEX_AOR 22
#define OCC 23
#define BG 24
#define AOR 25
#define SEX 26
#define NONE 27
#define CHECK_EXIST
typedef struct bst //2 names 2 aadhar no not found in search//y enered////update//edge conditions//all inputs //enter sorted//history of search/file not opened or no reults or nor no such database//remaing like occ
{
    char f_name[20],l_name[20];
    struct bst* left;
    struct bst* right;
    unsigned long int aadhar_no;
    char dob[11];
    char sex; // M or F
    char blood_group[5];
    char occupation[20];
    char area_of_resid[20];


}node;
typedef struct s_e_x
{
    char f_name[20],l_name[20];
    unsigned long int aadhar_no;
    char sex;
    int size;
}gender;
typedef struct bl_gp
{
    char f_name[20],l_name[20];
    unsigned long int aadhar_no;
    char blood_group[5];
    int size;
}blood_grp;
typedef struct aor
{
    char f_name[20],l_name[20];
    unsigned long int aadhar_no;
    char area_of_resid[20];
    int size;
}area_of_resid;
typedef struct prof
{
    char f_name[20],l_name[20];
    unsigned long int aadhar_no;
    char occupation[15];
    int size;
}occupation;
typedef struct bst2
{
    char f_name[20],l_name[20];
    struct bst2* left;
    struct bst2* right;
    unsigned long int name_id;
    unsigned long int aadhar_no;

}node2;
unsigned long int gen_name_id(char f_name[],char l_name[])
{
   int i,len1,len2;
   int name_id=0;
   char larger[10],smaller[10];
   len1=strlen(f_name);
   len2=strlen(l_name);
   if(len1>len2)
   {
       strcpy(larger,f_name);
       strcpy(smaller,l_name);
   }
   else
   {
       strcpy(larger,l_name);
       strcpy(smaller,f_name);
   }
   for(i=0;i<len1;i++)

       name_id+= f_name[i] * len2*1000;

    for(i=0;i<len2;i++) name_id+= l_name[i] * len1*1000;

    for(i=0;i<strlen(smaller);i++) name_id+= ((smaller[i]+larger[i])/2)* (len2+len1) ;

   return name_id;

}
//int write_con=0;
//int srch_con=0;
FILE* fp;
FILE* fp2;
FILE* fp3;
char F_NAME[20];
char L_NAME[20];
int found=0;
node2* create2(unsigned long int aadhar_no,unsigned long int name_id,char f_name[],char l_name[])
{

        node2* newnode2=(node2*)malloc(sizeof(node2));
         newnode2->name_id=name_id;
        newnode2->left=NULL;
        newnode2->right=NULL;
        newnode2->aadhar_no=aadhar_no;
        strcpy(newnode2->f_name,f_name);
        strcpy(newnode2->l_name,l_name);
        return newnode2;

}
void input_blood_grp(node* newnode,char mode[])
{
    char choice;
    while(1) {
            printf("Enter Blood Group:1.A+\t2.A-\t3.B+\t4.B-\t5.O+\t6.O-\t7.AB+\t8.AB-\n\nENTER CORRESPONDING NOUMBER\n");
            //what if wrong input

                scanf("%c",&choice);
                if(choice=='1') {strcpy(newnode->blood_group,"A+");fp3=fopen("A_pos.txt",mode   );fprintf(fp3,"%s %s %d %s\n",newnode->f_name,newnode->l_name,newnode->aadhar_no,newnode->blood_group);break;}
                else if(choice=='2') {strcpy(newnode->blood_group,"A-");fp3=fopen("A_neg.txt",mode);fprintf(fp3,"%s %s %d %s\n",newnode->f_name,newnode->l_name,newnode->aadhar_no,newnode->blood_group);break;}
                else if(choice=='3') {strcpy(newnode->blood_group,"B+");fp3=fopen("B_pos.txt",mode);fprintf(fp3,"%s %s %d %s\n",newnode->f_name,newnode->l_name,newnode->aadhar_no,newnode->blood_group);break;}
                else if(choice=='4') {strcpy(newnode->blood_group,"B-");fp3=fopen("B_neg.txt",mode);fprintf(fp3,"%s %s %d %s\n",newnode->f_name,newnode->l_name,newnode->aadhar_no,newnode->blood_group);break;}
                else if(choice=='5') {strcpy(newnode->blood_group,"O+");fp3=fopen("O_pos.txt",mode);fprintf(fp3,"%s %s %d %s\n",newnode->f_name,newnode->l_name,newnode->aadhar_no,newnode->blood_group);break;}
                else if(choice=='6') {strcpy(newnode->blood_group,"O-");fp3=fopen("O_neg.txt",mode);fprintf(fp3,"%s %s %d %s\n",newnode->f_name,newnode->l_name,newnode->aadhar_no,newnode->blood_group);break;}
                else if(choice=='7') {strcpy(newnode->blood_group,"AB+");fp3=fopen("AB_pos.txt",mode);fprintf(fp3,"%s %s %d %s\n",newnode->f_name,newnode->l_name,newnode->aadhar_no,newnode->blood_group);break;}
                else if(choice=='8') {strcpy(newnode->blood_group,"AB-");fp3=fopen("AB_neg.txt",mode);fprintf(fp3,"%s %s %d %s\n",newnode->f_name,newnode->l_name,newnode->aadhar_no,newnode->blood_group);break;}
                else printf("Incorrect Choice.Please Try Again\n");

        }
            fflush(stdin);
            fclose(fp3);
}
void input_sex(node* newnode,char mode[])
{
    char choice;
    while(1) {
            printf("Enter Gender\n1.Male\t2.Female\n\nENTER CORRESPONDING NOUMBER\n");
            //what if wrong input/
            //Cant use East space Delhi

                scanf("%c",&choice);
                if(choice=='1') {newnode->sex='M';fp3=fopen("masculine.txt",mode);fprintf(fp3,"%s %s %d %c\n",newnode->f_name,newnode->l_name,newnode->aadhar_no,newnode->sex);}
                else if(choice=='2') {newnode->sex='F';fp3=fopen("feminine.txt",mode);fprintf(fp3,"%s %s %d %c\n",newnode->f_name,newnode->l_name,newnode->aadhar_no,newnode->sex);}
                else printf("Incorrect Choice.Please Try Again\n");
                break;
        }
            fflush(stdin);
            fclose(fp3);
}
void input_area_of_resid(node* newnode,char mode[])
{
    char choice;
    while(1) {
            printf("Enter Area of Residence1.Ramnagar\t2.East Delhi3.South Delhi.4.North Delhi\t5.West Delhi\t6.Shantinagar\t7.Gopalnagar\t8.Shivajipeth\n\nENTER CORRESPONDING NOUMBER\n");
            //what if wrong input/
            //Cant use East space Delhi

                scanf("%c",&choice);
                if(choice=='1') {strcpy(newnode->area_of_resid,"Ramnagar");fp3=fopen("Ramnagar.txt",mode   );fprintf(fp3,"%s %s %d %s\n",newnode->f_name,newnode->l_name,newnode->aadhar_no,newnode->area_of_resid);break;}
                else if(choice=='2') {strcpy(newnode->area_of_resid,"East_Delhi");fp3=fopen("East_Delhi.txt",mode);fprintf(fp3,"%s %s %d %s\n",newnode->f_name,newnode->l_name,newnode->aadhar_no,newnode->area_of_resid);break;}
                else if(choice=='3') {strcpy(newnode->area_of_resid,"South_Delhi");fp3=fopen("South_Delhi.txt",mode);fprintf(fp3,"%s %s %d %s\n",newnode->f_name,newnode->l_name,newnode->aadhar_no,newnode->area_of_resid);break;}
                else if(choice=='4') {strcpy(newnode->area_of_resid,"North_Delhi");fp3=fopen("North_Delhi.txt",mode);fprintf(fp3,"%s %s %d %s\n",newnode->f_name,newnode->l_name,newnode->aadhar_no,newnode->area_of_resid);break;}
                else if(choice=='5') {strcpy(newnode->area_of_resid,"West_Delhi");fp3=fopen("West_Delhi.txt",mode);fprintf(fp3,"%s %s %d %s\n",newnode->f_name,newnode->l_name,newnode->aadhar_no,newnode->area_of_resid);break;}
                else if(choice=='6') {strcpy(newnode->area_of_resid,"Gopalnagar");fp3=fopen("Gopalnagar.txt",mode);fprintf(fp3,"%s %s %d %s\n",newnode->f_name,newnode->l_name,newnode->aadhar_no,newnode->area_of_resid);break;}
                else if(choice=='7') {strcpy(newnode->area_of_resid,"Shantinagar");fp3=fopen("Shantinagar.txt",mode);fprintf(fp3,"%s %s %d %s\n",newnode->f_name,newnode->l_name,newnode->aadhar_no,newnode->area_of_resid);break;}
                else if(choice=='8') {strcpy(newnode->area_of_resid,"Shivajipeth");fp3=fopen("Shivajipeth.txt",mode);fprintf(fp3,"%s %s %d %s\n",newnode->f_name,newnode->l_name,newnode->aadhar_no,newnode->area_of_resid);break;}
                else printf("Incorrect Choice.Please Try Again\n");

        }
            fflush(stdin);
            fclose(fp3);
}
void input_occupation(node* newnode,char mode[])
{
    char choice;
    while(1) {
            printf("Enter Profession/Occupation:1.Medical_Service(Doctor/Nurse,etc)\t2.Engineer\t3.Government Service\t4.Teacher");
            printf("                            5.Lawyer\t6.Self_Employed\t7.Housewife\t8.Unemployed\t9.Student\t10.Others\n\nENTER CORRESPONDING NOUMBER\n");   //common knowledge
            //what if wrong input

               scanf("%c",&choice);
                if(choice=='1') {strcpy(newnode->occupation,"Medical_Service");fp3=fopen("Medical_Service.txt",mode   );fprintf(fp3,"%s %s %d %s\n",newnode->f_name,newnode->l_name,newnode->aadhar_no,newnode->occupation);  break;}
                else if(choice=='2') {strcpy(newnode->occupation,"Engineer");fp3=fopen("Engineer.txt",mode);fprintf(fp3,"%s %s %d %s\n",newnode->f_name,newnode->l_name,newnode->aadhar_no,newnode->occupation);  break;}
                else if(choice=='3') {strcpy(newnode->occupation,"Government Service");fp3=fopen("Government Service.txt",mode);fprintf(fp3,"%s %s %d %s\n",newnode->f_name,newnode->l_name,newnode->aadhar_no,newnode->occupation);  break;}
                else if(choice=='4') {strcpy(newnode->occupation,"Teacher");fp3=fopen("Teacher.txt",mode);fprintf(fp3,"%s %s %d %s\n",newnode->f_name,newnode->l_name,newnode->aadhar_no,newnode->occupation);  break;}
                else if(choice=='5') {strcpy(newnode->occupation,"Lawyer");fp3=fopen("Lawyer.txt",mode);fprintf(fp3,"%s %s %d %s\n",newnode->f_name,newnode->l_name,newnode->aadhar_no,newnode->occupation);  break;}
                else if(choice=='6') {strcpy(newnode->occupation,"Self_Employed");fp3=fopen("Self_Employed.txt",mode);fprintf(fp3,"%s %s %d %s\n",newnode->f_name,newnode->l_name,newnode->aadhar_no,newnode->occupation);  break;}
                else if(choice=='7') {strcpy(newnode->occupation,"Housewife");fp3=fopen("Housewife.txt",mode);fprintf(fp3,"%s %s %d %s\n",newnode->f_name,newnode->l_name,newnode->aadhar_no,newnode->occupation);  break;}
                else if(choice=='8') {strcpy(newnode->occupation,"Unemployed");fp3=fopen("Unemployed.txt",mode);fprintf(fp3,"%s %s %d %s\n",newnode->f_name,newnode->l_name,newnode->aadhar_no,newnode->occupation);  break;}
                else if(choice=='9') {strcpy(newnode->occupation,"Student");fp3=fopen("Student.txt",mode);fprintf(fp3,"%s %s %d %s\n",newnode->f_name,newnode->l_name,newnode->aadhar_no,newnode->occupation);  break;}
                else if(choice=='10') {strcpy(newnode->occupation,"Others");fp3=fopen("Others.txt",mode);fprintf(fp3,"%s %s %d %s\n",newnode->f_name,newnode->l_name,newnode->aadhar_no,newnode->occupation);  break;}
                else printf("Incorrect Choice.Please Try Again\n");

        }
            fflush(stdin);
            fclose(fp3);
}
node* create(unsigned long int aadhar_no,char f_name[],char l_name[],int new_or_not)
{
            fflush(stdin);
            char mode[2];
            char choice;
            node* newnode=(node*)malloc(sizeof(node));
            newnode->left=NULL;
            newnode->right=NULL;
            (newnode->aadhar_no)=aadhar_no;
           // fflush(stdin);

            printf("Enter Date Of Birth(DD/MM/YY):");

            gets(newnode->dob);
            strcpy(newnode->f_name,f_name);
            strcpy(newnode->l_name,l_name);
             if(new_or_not==NEW) strcpy(mode,"w");
            else  strcpy(mode,"a");
            input_sex(newnode,mode);
            input_occupation(newnode,mode);
            input_blood_grp(newnode,mode);
            input_area_of_resid(newnode,mode);
            return newnode;

}

node2* ins_bst2(node2* rut2,unsigned long int aadhar_no,unsigned long int name_id,char f_name[],char l_name[])
{
    if(rut2==NULL)
     {

        rut2=create2(aadhar_no,name_id,f_name,l_name);
        printf("........Success.........\n!");

     }


    else if (name_id < (rut2->name_id))
        {
               rut2->left= ins_bst2(rut2->left,aadhar_no, name_id,f_name,l_name);
        }
    else if (name_id> (rut2->name_id)) //blunder one
        {
                rut2->right=ins_bst2(rut2->right,aadhar_no, name_id,f_name,l_name);
        }
        return rut2;
}
node* ins_bst(node* rut,unsigned long int aadhar_no,char f_name[],char l_name[],int new_or_not)
{
    if(rut==NULL)
     {

        rut=create(aadhar_no,f_name,l_name,new_or_not);
        printf("........Success.........\n!");

     }


    else if (aadhar_no < (rut->aadhar_no))
        {
               rut->left= ins_bst(rut->left, aadhar_no,f_name,l_name,new_or_not);
        }
    else if (aadhar_no> (rut->aadhar_no))
        {
                rut->right=ins_bst(rut->right, aadhar_no,f_name,l_name,new_or_not);
        }
        return rut;


}
void create_tree(node* root)
{
    if(root->left)
    {
        node* temp=(node*)malloc(sizeof(node));
        fread(temp,sizeof(node),1,fp);
        root->left=temp;
        create_tree(root->left);

    }
    if(root->right)
    {
         node* temp=(node*)malloc(sizeof(node));
        fread(temp,sizeof(node),1,fp);
        root->right=temp;
        create_tree(root->right);

    }

}
void create_tree2(node2* root2)
{
    if(root2->left)
    {
        node2* temp=(node2*)malloc(sizeof(node2));
        fread(temp,sizeof(node2),1,fp2);
        root2->left=temp;
        create_tree2(root2->left);

    }
    if(root2->right)
    {
         node2* temp=(node2*)malloc(sizeof(node2));
        fread(temp,sizeof(node2),1,fp2);
        root2->right=temp;
        create_tree2(root2->right);

    }

}
node* add2(node2* root2,int con,unsigned long int aadhar_no,char f_name[],char l_name[])
{
    unsigned long int name_id= gen_name_id(f_name,l_name);
    root2=ins_bst2(root2,aadhar_no,name_id,f_name,l_name);
    write_preorder2(root2,con);
    return root2;
}
void append2(unsigned long int aadhar_no,char f_name[],char l_name[],int new_or_not)
{
       node2* root2;
    if(new_or_not==OLD)
    {
         fp2=fopen("names.txt","r");
        root2=(node2*)malloc(sizeof(node2));
        fread(root2,sizeof(node2),1,fp2);
        create_tree2(root2);
        fclose(fp2);


    }
    else if(new_or_not==NEW)
   {
        //root2=(node2*)malloc(sizeof(node2));
       root2=NULL;

   }
    root2=add2(root2,1,aadhar_no,f_name,l_name);
    //return root;
    return;


}
node* add(node* root,int con) //adding in existing tree in buffer and recreating it in primary memory(Serializing).
{
    char f_name[20],l_name[20];
    int new_or_not,exist;
    if(root==NULL) new_or_not=NEW;
    else new_or_not=OLD;
    unsigned long int aadhar_no;
    printf("Enter Aadhar no\n");
    while(1){

    scanf("%ld",&aadhar_no);
    if((aadhar_no)) break; //isnum
    else printf("enter valid aadhar no");
    }
    exist=search_by_aadhar(root,aadhar_no);
    if(exist==1)
    {
        printf("Aadhar Number already exist.Please enter a proper aadhar no.!");
        return;
    }
    fflush(stdin);
    printf("\nEnter Name(FIRST_NAME LAST NAME)");
    printf("\nPlease Enter the credentials in the prescribed manner!\tOr expect Shit\n\t\t\t");
    scanf("%s %s",f_name,l_name);
    root=ins_bst(root,aadhar_no,f_name,l_name,new_or_not);
    write_preorder(root,1);
    append2(aadhar_no,f_name,l_name,new_or_not);
    return root;
}


void append() //De-serializing and redirecting to add node.
{
    fp=fopen("aadhar.txt","r");
    node* root=(node*)malloc(sizeof(node));
    fread(root,sizeof(node),1,fp);
    create_tree(root); //Is root pointing to NULL?
    fclose(fp);
    root=add(root,1);

    //return root;
    return;


}
void inorder(node* rut,int status)
{
    if(rut)
    {

        inorder(rut->left,status);
        if(status==PRINT)
        {
            printf("aadhar_no:%ld\t%s %s\n",rut->aadhar_no,rut->f_name,rut->l_name);
            printf("DOB:%s\t",rut->dob);
            printf("Blood_Group:%s\tSex:%c\n\n",rut->blood_group,rut->sex);
        }
        else if(status==SEARCH_F_NAME)
        {
            if(strcmp(F_NAME,rut->f_name)==0)
            {
                //printf("********FOUND********\n");
                show_details(rut);
                found=1;
               // return;
            }

        }
        else if(status==SEARCH_L_NAME)
        {
            if(strcmp(L_NAME,rut->l_name)==0)
            {
               // printf("********FOUND********\n");
                show_details(rut);
                found=1;
                //return;
            }

        }

        inorder(rut->right,status);
        return;
    }



}
void inorder2(node2* rut2)
{
    if(rut2)
    {

        inorder2(rut2->left);
       printf("aadhar_no:%8ld\t%10s %-10.8s\tName_id:%ld\n",rut2->aadhar_no,rut2->f_name,rut2->l_name,rut2->name_id);

        inorder2(rut2->right);
        return 0;
    }
    return 1;

}
void display(node* root)
{
     create_tree(root);
     inorder(root,PRINT);
     return;
}
void display2(node2* root2)
{
     create_tree2(root2);
     inorder2(root2);
     return;
}
void write_preorder(node* rut,int con) // USE DISPLAY ,SEARCH, WRITE AS ARGUMENTS
{

if(rut)
    {
        if(con==1)  fp=fopen("aadhar.txt","w");
        else  fp=fopen("aadhar.txt","a");

        fwrite(rut,sizeof(node),1,fp);
        fclose(fp);
        write_preorder(rut->left,0);
        write_preorder(rut->right,0);

        return;
    }
    else return;
}

void write_preorder2(node2* rut2,int con)
{

if(rut2)
    {
        if(con==1)  fp2=fopen("names.txt","w");
        else  fp2=fopen("names.txt","a");

        fwrite(rut2,sizeof(node2),1,fp2);
        fclose(fp2);
        write_preorder2(rut2->left,0);
        write_preorder2(rut2->right,0);

        return;
    }
    else return;
}
void show_details(node* rut)
{
        //char c;
        //while(1)
            //    {
                    //printf("Do you want more details?[y/n]");
          //         fflush(stdin);
                   // scanf("%c",&c);
                   // if(c=='y'||c=='Y')
                     //   {
                         //   system("cls");
                            printf("\n\n\n************************DETAILS******************\n\n\n");
                            printf("________________________________________________________\n\n");
                            printf("\t\t\tAadhar_no::%10ld\n",rut->aadhar_no);
                            printf("\t\t\tName:%10s %s\n",rut->f_name,rut->l_name);
                            printf("\t\t\tBlood Group:%10s\n\t\t\tDOB:%10s\n",rut->blood_group,rut->dob);
                            printf("\t\t\tOccupation:%10s\n\n\n",rut->occupation);
                            printf("\t\t\tArea of Residence:%10s\n\n\n",rut->area_of_resid);
                            printf("\t\t\tSEX:%10c\n\n\n",rut->sex);
                            printf("________________________________________________________\n\n");
                            printf("*************************************************");


                            return;
                        //}


                  /*  else if(c=='n'||c=='N')
                        return;
                    else
                       printf("Please input valid answer,dude!");*/
              //  }
}
void search_by_aadhar(node* rut,unsigned long int aadhar_no)
{



    if(rut==NULL) {system("cls");printf("\n\nNot FOund\n\n");}
    else if ((rut)&&((rut->aadhar_no)==aadhar_no))
    {
        //system("cls");
        printf("\t......$$Found$$.........\n");
        show_details(rut);return ;
        ;
    }   //  puts(rut->name);

    else if (aadhar_no < (rut->aadhar_no))
        {
               search_by_aadhar(rut->left, aadhar_no);
        }
    else if (aadhar_no> (rut->aadhar_no))
        {
               search_by_aadhar(rut->right, aadhar_no);
        }

}

void search_full_name(node2* root2 , unsigned long int name_id)
{
    if(root2)
    {
        if(root2->name_id==name_id)
        {
                node* root=(node*)malloc(sizeof(node));
                fp=fopen("aadhar.txt","r");  //make_tree()
                fread(root,sizeof(node),1,fp);
                create_tree(root);
                fclose(fp);
                search_by_aadhar(root,root2->aadhar_no);



        }
        else if(root2->name_id>name_id)

            search_full_name(root2->left,name_id);
        else if(root2->name_id<name_id)
              search_full_name(root2->right,name_id);
    }

    else {system("cls");printf("Not Found!");}
}

void search_by_name()
{
    int choice;
    while(1)
    {
    printf("Search by\n1.Full Name\t2.First_Name\t3.Last_Name:\n");
    scanf("%d",&choice);

    char f_name[20];
        char l_name[20];
    if(choice==1)
    {//why not switch
       unsigned long int name_id;
       node2* root2=(node2*)malloc(sizeof(node2));
        printf("Enter name(First_name Last_name:");
        scanf("%s %s",f_name,l_name);
        name_id=gen_name_id(f_name,l_name);
        fp2=fopen("names.txt","r");
        fread(root2,sizeof(node2),1,fp2);
        create_tree2(root2);
        fclose(fp2);
        system("cls");
        search_full_name(root2,name_id);
                break;
    }
    else if(choice==2)
    {
        node* root=(node*)malloc(sizeof(node));
        //char f_name[20];
        fflush(stdin);
        printf("Enter First Name:");
        gets(F_NAME);
        fp=fopen("aadhar.txt","r");
        fread(root,sizeof(node),1,fp);
        create_tree(root);
        fclose(fp);
        system("cls");
        inorder(root,SEARCH_F_NAME);
        if(found==0) printf("NOT FOUND!");
        else found=0;
                break;
    }
    else if(choice==3)
    {// char l_name[20];
        node* root=(node*)malloc(sizeof(node));
        fflush(stdin);
        printf("Enter Last Name:");
        gets(L_NAME);
        fp=fopen("aadhar.txt","r");
        fread(root,sizeof(node),1,fp);
        create_tree(root); //get in buffer
        fclose(fp);
        system("cls");
        inorder(root,SEARCH_L_NAME);
        if(found==0) printf("NOT FOUND!");
        else found=0;
        break;
    }
   else     printf("Wrong Choice,dude!Please Try Again.\n");

    }

}
/*void swap(blood_grp *bg1,blood_grp *bg2)
{

}*/
blood_grp* search_by_blood_grp(char filename[])
{
    system("cls");
    int size=0,i,j;
    fp3=fopen(filename,"r");
           if(fp3==NULL)
      {
          printf("FILE COULD NOT BE OPENDED");
          return;
      }
    blood_grp* bg;//fp==null
    char ch;
    char temp2[5];
    char temp3[15];
    char temp4[15];
    unsigned long int temp1;
    while(1)
        {



             if(feof(fp3))
            break;

        if(size==0)
        {
            bg=(blood_grp*)malloc(sizeof(blood_grp));
            fscanf(fp3,"%s %s %d %s\n",bg->f_name,bg->l_name,&(bg->aadhar_no),bg->blood_group);
        }
        else
        {
            bg=(blood_grp*)realloc(bg,(sizeof(blood_grp))*(size+1));
            fscanf(fp3,"%s %s %d %s\n",bg[size].f_name,bg[size].l_name,&(bg[size].aadhar_no),bg[size].blood_group);
        }
        size++;
       //   no of elements..

      }
    bg->size=size;

        for(i=0;i<bg->size-1;i++)
        {
            for(j=0;j<bg->size-i-1;j++)
            {
                if(bg[j].aadhar_no>bg[j+1].aadhar_no)
                   {

                        temp1=bg[j].aadhar_no;
                       bg[j].aadhar_no=bg[j+1].aadhar_no;
                       bg[j+1].aadhar_no=temp1;

                       strcpy(temp2,bg[j].blood_group);
                        strcpy(bg[j].blood_group,bg[j+1].blood_group);
                        strcpy(bg[j+1].blood_group,temp2);

                        strcpy(temp3,bg[j].f_name);
                        strcpy(bg[j].f_name,bg[j+1].f_name);
                        strcpy(bg[j+1].f_name,temp3);

                        strcpy(temp4,bg[j].l_name);
                        strcpy(bg[j].l_name,bg[j+1].l_name);
                        strcpy(bg[j+1].l_name,temp4);
                       /*temp=&bg[j];
                       bg[j]=bg[j+1];
                       bg[j+1]=*temp;*/
                    }
            }
        }
        bg->size=size;
    fclose(fp3);
 fflush(stdin);
 return bg;
}
area_of_resid* search_by_area_of_resid(char filename[])
{
    system("cls");
    int size=0,i,j;
    char ch;
    unsigned long int temp1;
    char temp2[15];
    char temp3[15];
    char temp4[15];
    fp3=fopen(filename,"r");
         if(fp3==NULL)
      {
          printf("FILE COULD NOT BE OPENDED");
          return;
      }
    area_of_resid *aor;//fp==null
    while(1)

{


             if(feof(fp3))
            break;

        if(size==0)
        {
            aor=(area_of_resid*)malloc(sizeof(area_of_resid));
            fscanf(fp3,"%s %s %d %s\n",aor[0].f_name,aor[0].l_name,&(aor[0].aadhar_no),aor[0].area_of_resid);
         }//aor->area_of_resid
        else
        {
            aor=(area_of_resid*)realloc(aor,(sizeof(area_of_resid))*(size+1));
            fscanf(fp3,"%s %s %d %s\n",aor[size].f_name,aor[size].l_name,&(aor[size].aadhar_no),aor[size].area_of_resid);//*(aor+size).name ie (aor+size)->name
        }
        size++;
       //   \n?

    }

    aor->size=size;
            for(i=0;i<aor->size-1;i++)
        {
            for(j=0;j<aor->size-i-1;j++)
            {
                if(aor[j].aadhar_no>aor[j+1].aadhar_no)
                   {

                        temp1=aor[j].aadhar_no;
                       aor[j].aadhar_no=aor[j+1].aadhar_no;
                       aor[j+1].aadhar_no=temp1;

                       strcpy(temp2,aor[j].area_of_resid);
                        strcpy(aor[j].area_of_resid,aor[j+1].area_of_resid);
                        strcpy(aor[j+1].area_of_resid,temp2);

                        strcpy(temp3,aor[j].f_name);
                        strcpy(aor[j].f_name,aor[j+1].f_name);
                        strcpy(aor[j+1].f_name,temp3);

                        strcpy(temp4,aor[j].l_name);
                        strcpy(aor[j].l_name,aor[j+1].l_name);
                        strcpy(aor[j+1].l_name,temp4);
                       /*temp=&aor[j];
                       aor[j]=aor[j+1];
                       aor[j+1]=*temp;*/
                    }
            }
        }
        aor->size=size;

    fclose(fp3);
     fflush(stdin);
 return aor;

}
gender* search_by_sex(char filename[])
{
    system("cls");
    int size=0,i,j;
    fp3=fopen(filename,"r");
         if(fp3==NULL)
      {
          printf("FILE COULD NOT BE OPENDED");
          return;
      }
     unsigned long int temp1;
    char temp2;
    char temp3[15];
    char temp4[15];
    gender* sex;//fp==null
    while(1)

    {


             if(feof(fp3))
            break;

        if(size==0)
        {
            sex=(gender*)malloc(sizeof(gender));
            fscanf(fp3,"%s %s %d %c\n",sex[0].f_name,sex[0].l_name,&(sex[0].aadhar_no),&sex[0].sex);
         }//sex->gender
        else
        {
            sex=(gender*)realloc(sex,(sizeof(gender))*(size+1));
            fscanf(fp3,"%s %s %d %c\n",sex[size].f_name,sex[size].l_name,&(sex[size].aadhar_no),&sex[size].sex);//*(sex+size).name ie (sex+size)->name
        }
        size++;
       //   \n?

    }

    sex->size=size;
                for(i=0;i<sex->size-1;i++)
        {
            for(j=0;j<sex->size-i-1;j++)
            {
                if(sex[j].aadhar_no>sex[j+1].aadhar_no)
                   {

                        temp1=sex[j].aadhar_no;
                       sex[j].aadhar_no=sex[j+1].aadhar_no;
                       sex[j+1].aadhar_no=temp1;

                        temp2=sex[j].sex;
                       sex[j].sex=sex[j+1].sex;
                       sex[j+1].sex=temp2;

                        strcpy(temp3,sex[j].f_name);
                        strcpy(sex[j].f_name,sex[j+1].f_name);
                        strcpy(sex[j+1].f_name,temp3);

                        strcpy(temp4,sex[j].l_name);
                        strcpy(sex[j].l_name,sex[j+1].l_name);
                        strcpy(sex[j+1].l_name,temp4);
                       /*temp=&sex[j];
                       sex[j]=sex[j+1];
                       aor[j+1]=*temp;*/
                    }
            }
        }
        sex->size=size;


    fclose(fp3);
     fflush(stdin);
 return sex;

}
occupation* search_by_occupation(char filename[])
{
    //system("cls");
    fp3=fopen(filename,"r");
         if(fp3==NULL)
      {
          printf("FILE COULD NOT BE OPENDED");
          return;
      }
    occupation* ocp;
    int size=0;
    //fp==null
    while(1)

{


             if(feof(fp3))
            break;

        if(size==0)
        {
            ocp=(occupation*)malloc(sizeof(occupation));
            fscanf(fp3,"%s %s %d %s\n",ocp[0].f_name,ocp[0].l_name,&(ocp[0].aadhar_no),ocp[0].occupation);
         }//ocp->occupation
        else
        {
            ocp=(occupation*)realloc(ocp,(sizeof(occupation))*(size+1));
            fscanf(fp3,"%s %s %d %s\n",ocp[size].f_name,ocp[size].l_name,&(ocp[size].aadhar_no),ocp[size].occupation);//*(ocp+size).name ie (ocp+size)->name
        }
        size++;
       //   \n?

    }
    ocp->size=size;
    fclose(fp3);
     fflush(stdin);
 return ocp;

}
int bin_s_bg(unsigned long int aadhar_no,blood_grp* bg,int left,int right)
{
     int mid=(left+right)/2;

    if(aadhar_no==bg[mid].aadhar_no)
    {

        return 1;
    }
   // else if((left==mid||right==mid))  {printf("NOt Found\t%ld\n",aadhar_no);return 0;}
   else if(left==(right-1))
           {
               if(aadhar_no==bg[right].aadhar_no||aadhar_no==bg[left].aadhar_no)
                   {

                    return 1;
                   }
               else{return 0;}
           }
    else if(aadhar_no>bg[mid].aadhar_no)
    {

        bin_s_bg(aadhar_no,bg,mid,right);
    }
    else if(aadhar_no<bg[mid].aadhar_no)
    {

        bin_s_bg(aadhar_no,bg,left,mid);
    }




}
int bin_s_ocp(unsigned long int aadhar_no,occupation* ocp,int left,int right)// simple less line codes try
 {
   int mid=(left+right)/2;

    if(aadhar_no==ocp[mid].aadhar_no)
    {

        return 1;
    }
   // else if((left==mid||right==mid))  {printf("NOt Found\t%ld\n",aadhar_no);return 0;}
   else if(left==(right-1))
           {
               if(aadhar_no==ocp[right].aadhar_no||aadhar_no==ocp[left].aadhar_no)
                   {

                    return 1;
                   }
               else{return 0;}
           }
    else if(aadhar_no>ocp[mid].aadhar_no)
    {

        bin_s_ocp(aadhar_no,ocp,mid,right);
    }
    else if(aadhar_no<ocp[mid].aadhar_no)
    {

        bin_s_ocp(aadhar_no,ocp,left,mid);
    }
 }

int bin_s_sex(unsigned long int aadhar_no,gender* sex,int left,int right)
{
    int mid=(left+right)/2;

    if(aadhar_no==sex[mid].aadhar_no)
    {

        return 1;
    }
   // else if((left==mid||right==mid))  {printf("NOt Found\t%ld\n",aadhar_no);return 0;}
   else if(left==(right-1))
           {
               if(aadhar_no==sex[right].aadhar_no||aadhar_no==sex[left].aadhar_no)
                   {

                    return 1;
                   }
               else{return 0;}
           }
    else if(aadhar_no>sex[mid].aadhar_no)
    {

        bin_s_sex(aadhar_no,sex,mid,right);
    }
    else if(aadhar_no<sex[mid].aadhar_no)
    {

        bin_s_sex(aadhar_no,sex,left,mid);
    }




}
int bin_s_aor(unsigned long int aadhar_no,area_of_resid* aor,int left,int right)
{
    int mid=(left+right)/2;

    if(aadhar_no==aor[mid].aadhar_no)
    {

        return 1;
    }
   // else if((left==mid||right==mid))  {printf("NOt Found\t%ld\n",aadhar_no);return 0;}
   else if(left==(right-1))
           {
               if(aadhar_no==aor[right].aadhar_no||aadhar_no==aor[left].aadhar_no)
                   {

                    return 1;
                   }
               else{return 0;}
           }
    else if(aadhar_no>aor[mid].aadhar_no)
    {

        bin_s_aor(aadhar_no,aor,mid,right);
    }
    else if(aadhar_no<aor[mid].aadhar_no)
    {

        bin_s_aor(aadhar_no,aor,left,mid);
    }




}
area_of_resid* subseq_search_from_aor(area_of_resid* aor,char filename[],int type)
{
    system("cls");
    int size,size2;
    int i=0,j;
    if(type==OCC)
   {
        occupation* ocp=NULL;
        ocp=search_by_occupation(filename);
        if(ocp==NULL)
        {
          printf("FILE COULD NOT BE OPENDED");
          return;
        }
        size=aor->size;
        size2=ocp->size;
    //why outside
        while(i<size)
        {
            if(bin_s_ocp(aor[i].aadhar_no,ocp,0,size2-1)) // binary search aor[i] 's addhar no in ocp
            {

                i++;
            }

            else
                {
                aor[i].aadhar_no=aor[size-1].aadhar_no;
                strcpy(aor[i].f_name,aor[size-1].f_name);
                strcpy(aor[i].l_name,aor[size-1].l_name);
                free(&aor[size-1]);
                (size)--;
                }


        }
        if(size==0)   {printf("no results"); aor=NULL;}
        else
        {
            i=0;
            aor->size=size;
            //system("cls");
            printf("************************sucess.************************\n******************************\n\n\tCATEGORY:\t%s\n\n",ocp->occupation);
            printf("***********************************************************************\n");
                                printf("***********************************************************************\n");
                                printf("_______________________________________________________________________\n");
            printf("\t\t\tTotal Results:%d\n\n",size);
            while(i<size)
            {
                printf("%d)\t%s %s %d %s\n\n\n",i+1,aor[i].f_name,aor[i].l_name,aor[i].aadhar_no,aor[i].area_of_resid); //
                i++;
            }  printf("_______________________________________________________________________\n");
            printf("***********************************************************************\n");
                                printf("***********************************************************************\n");

            printf("Press serial no to get details:\n");
            printf("Press A to get details of obtained results");




        }

   }
   else if(type==BG)
    {
        blood_grp* bg=NULL;
        bg=search_by_blood_grp(filename);
        if(bg==NULL)
      {
          printf("FILE COULD NOT BE OPENDED");
          return;
      }
        size=aor->size;
        size2=bg->size;

    //why outside
        while(i<size)
        {
            if(bin_s_bg(aor[i].aadhar_no,bg,0,size2-1))
            {
                i++;
            }
            else
                {
                aor[i].aadhar_no=aor[size-1].aadhar_no;
                strcpy(aor[i].f_name,aor[size-1].f_name);
                strcpy(aor[i].l_name,aor[size-1].l_name);
                free(&aor[size-1]);
                (size)--;
                }


        }
      if(size==0)   {printf("no results"); aor=NULL;}
        else
        {
            i=0;
             aor->size=size;
            printf("******************************sucess.*******************************\n**********************************************\n\nCATEGORY:\t\t%s\n\n",bg->blood_group);
            printf("\t\t\tTotal Results:%d\n\n",size);
            while(i<size)
            {
                printf("%d)\t%s %s %d %s\n\n\n",i+1,aor[i].f_name,aor[i].l_name,aor[i].aadhar_no,aor[i].area_of_resid); //
                i++;
            }
            printf("***********************************************************************\n");
                                printf("***********************************************************************\n");
                                printf("_______________________________________________________________________\n");
            printf("Press serial no to get details:\n");
            printf("Press A to get details of obtained results");
        }
    }

   else if(type==SEX)
   {
        gender* sex =NULL;
        sex=search_by_sex(filename);
           if(sex==NULL)
      {
          printf("FILE COULD NOT BE OPENDED");
          return;
      }
        size=aor->size;
        size2=sex->size;
    //why outside
        while(i<size)
        {
            if(bin_s_sex(aor[i].aadhar_no,sex,0,size2-1))
                i++;
            else
                {
                aor[i].aadhar_no=aor[size-1].aadhar_no;
                strcpy(aor[i].f_name,aor[size-1].f_name);
                strcpy(aor[i].l_name,aor[size-1].l_name);
                free(&aor[size-1]);
                (size)--;
                }


        }
        if(size==0)   {printf("no results"); aor=NULL;}
        else
        {
            i=0;
             aor->size=size;
            printf("***********************************success.*******************\n*****************************\n\n\tCATEGORY:\t%c\n\n",sex->sex);
            printf("\t\t\tTotal Results:%d\n\n",size);   printf("_______________________________________________________________________\n");
            while(i<size)
            {
                printf("%d)\t%s %s %d %s\n\n\n",i+1,aor[i].f_name,aor[i].l_name,aor[i].aadhar_no,aor[i].area_of_resid); //
                i++;
            }printf("***********************************************************************\n");
                                printf("***********************************************************************\n");
                                printf("_______________________________________________________________________\n");
            printf("Press serial no to get details:\n");
            printf("Press A to get details of obtained results\n0");



        }
   }
return aor;

}
blood_grp* subseq_search_from_bg(blood_grp* bg,char filename[],int type)
{
    system("cls");
    int size,size2;
    int i=0,j;
    if(type==OCC)
   {
        occupation* ocp=NULL;
        ocp=search_by_occupation(filename);
      //  printf("\n\n%d\n\n",bg->size);
      if(ocp==NULL)
      {
          printf("FILE COULD NOT BE OPENDED");
          return;
      }
        size=bg->size;
        size2=ocp->size;
    //why outside
        while(i<size)
        {
            if(bin_s_ocp(bg[i].aadhar_no,ocp,0,size2-1))
            {

                i++;
            }

            else
                {
                bg[i].aadhar_no=bg[size-1].aadhar_no;
                strcpy(bg[i].f_name,bg[size-1].f_name);
                strcpy(bg[i].l_name,bg[size-1].l_name);
                free(&bg[size-1]);
                (size)--;
                }


        }
        if(size==0)   {printf("no results"); bg=NULL;}
        else
        {
            i=0;
            bg->size=size;
            printf("**************************************sucess.************\n*********************************************\n\n\tCATEGORY\t%s\n\n",ocp->occupation);
            printf("\t\t\tTotal Results:%d\n\n",size); printf("_______________________________________________________________________\n");
            while(i<size)
            {
                printf("%d)\t%s %s %d %s\n\n\n",i+1,bg[i].f_name,bg[i].l_name,bg[i].aadhar_no,bg[i].blood_group); //
                i++;
            }printf("***********************************************************************\n");
                                printf("***********************************************************************\n");
                                printf("_______________________________________________________________________\n");
            printf("Press serial no to get details:\n");
            printf("Press A to get details of obtained results");




        }

   }
    else if(type==AOR)
    {
        area_of_resid* aor=NULL;
        aor=search_by_area_of_resid(filename);
        if(aor==NULL)
      {
          printf("FILE COULD NOT BE OPENDED");
          return;
      }
        size=bg->size;
        size2=aor->size;

    //why outside
        while(i<size)
        {
            if(bin_s_aor(bg[i].aadhar_no,aor,0,size2-1))
            {
                i++;
            }
            else
                {
                bg[i].aadhar_no=bg[size-1].aadhar_no;
                strcpy(bg[i].f_name,bg[size-1].f_name);
                strcpy(bg[i].l_name,bg[size-1].l_name);
                free(&bg[size-1]);
                (size)--;
                }


        }
      if(size==0)   {printf("no results"); bg=NULL;}
        else
        {
            i=0;
             bg->size=size;
            printf("********************************************************sucess.*********************************\n******************************************\n\n\tCATEGORY::\t%s\n\n",aor->area_of_resid);
            printf("\t\t\tTotal Results:%d\n\n",size);
            printf("_______________________________________________________________________\n");
            while(i<size)
            {
                printf("%d)\t%s %s %d %s\n\n\n",i+1,bg[i].f_name,bg[i].l_name,bg[i].aadhar_no,bg[i].blood_group); //
                i++;
            }printf("***********************************************************************\n");
                                printf("***********************************************************************\n");
                                printf("_______________________________________________________________________\n");
            printf("Press serial no to get details:\n");
            printf("Press A to get details of obtained results");
        }
    }

   else if(type==SEX)
   {
        gender* sex =NULL;
        sex=search_by_sex(filename);
           if(sex==NULL)
      {
          printf("FILE COULD NOT BE OPENDED");
          return;
      }
        size=bg->size;
        size2=sex->size;
    //why outside
        while(i<size)
        {
            if(bin_s_sex(bg[i].aadhar_no,sex,0,size2-1))
                i++;
            else
                {
                bg[i].aadhar_no=bg[size-1].aadhar_no;
                strcpy(bg[i].f_name,bg[size-1].f_name);
                strcpy(bg[i].l_name,bg[size-1].l_name);
                free(&bg[size-1]);
                (size)--;
                }


        }
        if(size==0)   {printf("no results"); bg=NULL;}
        else
        {
            i=0;
             bg->size=size;
            printf("***********************************************success.**************************************\n*****************************************************\n\nCATEGORY:\t\t%\n\n",sex->sex);
            printf("\t\t\tTotal Results:%d\n\n",size); printf("_______________________________________________________________________\n");
            while(i<size)
            {
                printf("%d)\t%s %s %d %s\n\n\n",i+1,bg[i].f_name,bg[i].l_name,bg[i].aadhar_no,bg[i].blood_group); //
                i++;
            }printf("***********************************************************************\n");
                                printf("***********************************************************************\n");
                                printf("_______________________________________________________________________\n");
            printf("Press serial no to get details:\n");
            printf("Press A to get details of obtained results\n0");



        }
   }
return bg;

}
occupation* subseq_search_from_occ(occupation* ocp,char filename[],int type)
{
    system("cls");
    char ch;
    int ser;
    int size,size2;
    node* root=NULL;
    int i=0,j;
    if(type==BG)
   {
        blood_grp* bg=NULL;
        bg=search_by_blood_grp(filename);
        printf("\n\n%d\n\n",ocp->size);
      if(bg==NULL)
      {
          printf("FILE COULD NOT BE OPENDED");
          return;
      }
        size=ocp->size;
        size2=bg->size;
         // printf("\n\n%d\n\n%d",size2,size);
    //why outside
        while(i<size)
        {
            if(bin_s_bg(ocp[i].aadhar_no,bg,0,size2-1))
            {

                i++;

            }

            else
                {

                ocp[i].aadhar_no=ocp[size-1].aadhar_no;
                strcpy(ocp[i].f_name,ocp[size-1].f_name);
                strcpy(ocp[i].l_name,ocp[size-1].l_name);
                free(&ocp[size-1]);

                (size)--;
                }


        }
        if(size==0)   {printf("no results"); ocp=NULL;}
        else
        {
            i=0;
            ocp->size=size;
            printf("**********************************************sucess.*************************************\n********************************************\n\n\tCATEGORY:\t%s\n\n",bg->blood_group);
            printf("\t\t\tTotal Results:%d\n\n",size); printf("_______________________________________________________________________\n");
            while(i<size)
            {
                printf("%d)\t%s %s %d %s\n\n\n",i+1,ocp[i].f_name,ocp[i].l_name,ocp[i].aadhar_no,ocp[i].occupation); //
                i++;
            }printf("***********************************************************************\n");
                                printf("***********************************************************************\n");
                                printf("_______________________________________________________________________\n");
          }








   }
     if(type==AOR)
    {
        area_of_resid* aor=NULL;
        aor=search_by_area_of_resid(filename);
        if(aor==NULL)
      {
          printf("FILE COULD NOT BE OPENDED");
          return;
      }
        size=ocp->size;
        size2=aor->size;

    //why outside
        while(i<size)
        {
            if(bin_s_aor(ocp[i].aadhar_no,aor,0,size2-1))
            {
                i++;
            }
            else
                {
                ocp[i].aadhar_no=ocp[size-1].aadhar_no;
                strcpy(ocp[i].f_name,ocp[size-1].f_name);
                strcpy(ocp[i].l_name,ocp[size-1].l_name);
                free(&ocp[size-1]);
                (size)--;
                }


        }
      if(size==0)   {printf("no results"); ocp=NULL;}
        else
        {
            i=0;
             ocp->size=size;
            printf("***********************************************sucess.********************************************\n*****************************************************\n\n\tCATEGORY:\t%s\n\n",aor->area_of_resid);
            printf("\t\t\tTotal Results:%d\n\n",size);   printf("_______________________________________________________________________\n");
            while(i<size)
            {
                printf("%d)\t%s %s %d %s\n\n\n",i+1,ocp[i].f_name,ocp[i].l_name,ocp[i].aadhar_no,ocp[i].occupation); //
                i++;
            }printf("***********************************************************************\n");
                                printf("***********************************************************************\n");
                                printf("_______________________________________________________________________\n");
            printf("Press serial no to get details:\n");
            printf("Press A to get details of obtained results");
        }
    }

   else if(type==SEX)
   {
        gender* sex =NULL;
        sex=search_by_sex(filename);
           if(sex==NULL)
      {
          printf("FILE COULD NOT BE OPENDED");
          return;
      }
        size=ocp->size;
        size2=sex->size;
    //why outside
        while(i<size)
        {
            if(bin_s_sex(ocp[i].aadhar_no,sex,0,size2-1))
                i++;
            else
                {
                ocp[i].aadhar_no=ocp[size-1].aadhar_no;
                strcpy(ocp[i].f_name,ocp[size-1].f_name);
                strcpy(ocp[i].l_name,ocp[size-1].l_name);
                free(&ocp[size-1]);
                (size)--;
                }


        }
        if(size==0)   {printf("no results"); ocp=NULL;}
        else
        {
            i=0;
             ocp->size=size;
            printf("***************************************************success.***********************************************************\n***************************************************************\n\n\tCATEGORY:\t%c\n\n",sex->sex);
            printf("\t\t\tTotal Results:%d\n\n",size);   printf("_______________________________________________________________________\n");
            while(i<size)
            {
                printf("%d)\t%s %s %d %s\n\n\n",i+1,ocp[i].f_name,ocp[i].l_name,ocp[i].aadhar_no,ocp[i].occupation); //
                i++;
            }printf("***********************************************************************\n");
                                printf("***********************************************************************\n");
                                printf("_______________________________________________________________________\n");
            printf("Press serial no to get details:\n");
            printf("Press A to get details of obtained results\n0");



        }
   }
return ocp;

}
void bg_sub_search(blood_grp* bg,int type,int status)
{

    char ch;
    int ser,ans,num;
    node* root=NULL;
    char choice;
    char ans2;
    if(type==OCC)
    {
      CHECKPOIN1 :while(1){
                         printf("Search for which Profession/Occupation individuals?\n\n:1.Medical_Service(Doctor/Nurse,etc)\t2.Engineer\t3.Government Service\t4.Teacher");
                          printf("5.Lawyer\t6.Self_Employed\t7.Housewife\t8.Unemployed\t9.Student\t10.Others\n\nENTER CORRESPONDING NOUMBER\n");
                         fflush(stdin);//do for combinations
                         scanf("%c",&choice);
                         if(choice=='1') {bg=subseq_search_from_bg(bg,"Medical_Service.txt",OCC);break;}
                         if(choice=='2') {bg=subseq_search_from_bg(bg,"Engineer.txt",OCC);break;}
                         if(choice=='3') {bg=subseq_search_from_bg(bg,"Government Service.txt",OCC);break;}
                         if(choice=='4') {bg=subseq_search_from_bg(bg,"Teacher.txt",OCC);break;}
                         if(choice=='5') {bg=subseq_search_from_bg(bg,"Lawyer.txt",OCC);break;}
                         if(choice=='6') {bg=subseq_search_from_bg(bg,"Self_Employed.txt",OCC);break;}
                         if(choice=='7') {bg=subseq_search_from_bg(bg,"Housewife.txt",OCC);break;}
                         if(choice=='8') {bg=subseq_search_from_bg(bg,"Unemployed.txt",OCC);break;}
                         if(choice=='9') {bg=subseq_search_from_bg(bg,"Student.txt",OCC);break;}
                         if(choice=='10') {bg=subseq_search_from_bg(bg,"Others.txt",OCC);break;}
                         else printf("Incorrect Choice.Please Try Again\n");
                        }
                if(bg!=NULL){
                             printf("press -5 to get details of all listed persons\n");
                             printf("type the serial no to get details of a PARTICULAR person :\nreturn to main menu type-1\n]");
                             // if(status!=NONE)printf("Are you even more keen interested further search in obtained results??[yes:press 0]\n");

                            scanf("%d",&ser);if(ser==-5)
                            {

                            node* root=(node*)malloc(sizeof(node));
                            fp=fopen("aadhar.txt","r");  //make_tree()
                            fread(root,sizeof(node),1,fp);
                            create_tree(root);
                            fclose(fp);
                            system("cls");
                            for(num=0;num<bg->size;num++)

                            {search_by_aadhar(root,bg[num].aadhar_no);}


                            printf("press 0 to go back to search individuals with various OCCUPATIONS again\nPress -1 to go to main menu:\npress 2 to continue further searchingin previously obtained results:");
                            scanf("%d",&ans);if(ans==-1){system("cls");printf("\n\n**********We were delighted to  help you!:)\t*****\nThank you.");return;}if(ans==0)goto CHECKPOIN1  ;
                            }
                                    else if(ser==-1){system("cls");printf("\n\n**********We were delighted to  help you!:)\t*****\ngood luck\n");return;}
                                    else if((ser)>0){
                                    node* root=(node*)malloc(sizeof(node));
                                    fp=fopen("aadhar.txt","r");  //make_tree()
                                    fread(root,sizeof(node),1,fp);
                                    create_tree(root);
                                    fclose(fp);
                                    system("cls");
                                    search_by_aadhar(root,bg[ser-1].aadhar_no);
                                    printf("press 0 to go back to search individuals with various OCCUPATIONS again\nPress -1 to go to main menu:\npress 2 to continue further searchingin previously obtained results:");
                                    scanf("%d",&ans);if(ans==-1){system("cls");printf("\n\n**********We were delighted to  help you!:)\t*****\nThank you.");return;}if(ans==0)goto CHECKPOIN1 ;
                                    }
                                     if(status!=NONE){
                                    if(ans==2||ser==0)
                                    {
                                        if(status==SEX_AOR&&bg!=NULL)

                                        {
                                            fflush(stdin);
                                            printf("1.Area of Residence\n2.Sex\nPress correspinding digit\t:");
                                            fflush(stdin);
                                            scanf("%c",&ans2);
                                            if(ans2=='1'){ bg_sub_search(bg,AOR,SEX);}
                                            else if(ans2=='2')bg_sub_search(bg,SEX,AOR);
                                            else printf("Incorrect input.Please try again:)");
                                        }
                                        else if(status==AOR&&bg!=NULL)
                                        {
                                            fflush(stdin);
                                            printf("1.Area of Residence\nPress correspinding digit\t:");
                                            scanf("%c",&ans2);
                                            if(ans2=='1'){bg_sub_search(bg,AOR,NONE);}
                                            else {printf("Incorrect input.Please Try Again:)");}

                                        }
                                        else if(status==SEX&&bg!=NULL)
                                        {
                                            fflush(stdin);
                                            printf("1.Sex\nPress correspinding digit\t:");
                                            scanf("%c",&ans2);
                                            if(ans2=='1') {bg_sub_search(bg,SEX,NONE);}
                                            else {printf("Incorrect input.Please Try Again:)");}
                                        }
                                        else {system("cls"); printf("\n\n**********We were delighted to  help you!:)\t*****\n");return ;}
                                }
                                 else {printf("Incorrect input.Please Try Again:)");}
                }
                else if (status==NONE){system("cls"); printf("Sorry.Thats it what we could do to you!\n\nAnyways,we were delighted to  help you!:)\t*****\n");return ;}
                else {system("cls"); printf("\n\n**********We were delighted to  help you!:)\t*****\n");return ;}

                }
                else {system("cls"); printf("No Results!\n\n**********We were delighted to  help you!:)\t*****\n");return ;}

    }
     else if(type==AOR)
    {
                CHECKPOIN2:  while(1){
                                    printf("Search for which area individuals\n1.Ramnagar\t2.East Delhi3.South Delhi.4.North Delhi\t5.West Delhi\t6.Shantinagar\t7.Gopalnagar\t8.Shivajipeth\n\nENTER CORRESPONDING NOUMBER\n");
            //what if wrong input
                                    fflush(stdin);//do for combinations
                                    scanf("%c",&choice);
                                    if(choice=='1') {bg=subseq_search_from_bg(bg,"Ramnagar.txt",AOR);break;}
                                    if(choice=='2') {bg=subseq_search_from_bg(bg,"East_Delhi.txt",AOR);break;}
                                    if(choice=='3') {bg=subseq_search_from_bg(bg,"South_Delhi.txt",AOR);break;}
                                    if(choice=='4') {bg=subseq_search_from_bg(bg,"North_Delhi.txt",AOR);break;}
                                    if(choice=='5') {bg=subseq_search_from_bg(bg,"West_Delhi.txt",AOR);break;}
                                    if(choice=='6') {bg=subseq_search_from_bg(bg,"Shantinagar.txt",AOR);break;}
                                    if(choice=='7') {bg=subseq_search_from_bg(bg,"Gopalnagar.txt",AOR);break;}
                                    if(choice=='8') {bg=subseq_search_from_bg(bg,"Shivajipeth.txt",AOR);break;}

                                    else printf("Incorrect Choice.Please Try Again\n");
                                    }
                            if(bg!=NULL){
                               printf("press -5 to get details of all listed persons\n");
                                printf("type the serial no to get details of a PARTICULAR person :\nAre you even more keen interested further search in obtained results??[yes:press 0]\nreturn to main menu type-1\n]");
                                scanf("%d",&ser);
                                if(ser==-5)
                                {

                                    node* root=(node*)malloc(sizeof(node));
                                    fp=fopen("aadhar.txt","r");  //make_tree()
                                    fread(root,sizeof(node),1,fp);
                                    create_tree(root);
                                    fclose(fp);
                                    system("cls");
                                    for(num=0;num<bg->size;num++){search_by_aadhar(root,bg[num].aadhar_no);}

                                    printf("press 0 to go back to search different RESIDENTS again\nPress -1 to go to main menu:\npress 2 to continue further searchingin previously obtained results:");
                                    scanf("%d",&ans);if(ans==-1){system("cls");printf("\n\n**********We were delighted to  help you!:)\t*****\nThank you.");return;}if(ans==0)goto CHECKPOIN2;
                                }
                                else if(ser==-1){system("cls");printf("\n\n**********We were delighted to  help you!:)\t*****\ngood luck\n");return;}
                                else if((ser)>0){
                                        node* root=(node*)malloc(sizeof(node));
                                        fp=fopen("aadhar.txt","r");  //make_tree()
                                        fread(root,sizeof(node),1,fp);
                                        create_tree(root);
                                        fclose(fp);
                                        system("cls");
                                        search_by_aadhar(root,bg[ser-1].aadhar_no);
                                        printf("press 0 to go back to search different RESIDENTS  again\nPress -1 to go to main menu:\npress 2 to continue further searchingin previously obtained results:");
                                        scanf("%d",&ans);if(ans==-1){system("cls");printf("\n\n**********We were delighted to  help you!:)\t*****\nThank you.");return;}if(ans==0)goto CHECKPOIN2;
                                            }
                                                                        if(status!=NONE){
                                if(ans==2||ser==0)
                                {
                                    if(status==SEX_OCC&&bg!=NULL){
                                        fflush(stdin);
                                        printf("1.Occupation\n2.Sex\nPress corresponding digit\t:");
                                        scanf("%c",&ans2);
                                        if(ans2=='1'){bg_sub_search(bg,OCC,SEX);}
                                        else if(ans2=='2'){bg_sub_search(bg,SEX,OCC);}
                                        else {printf("Wrong Input....Please try again\n:)");}
                                        }

                                    else if(status==OCC&&bg!=NULL)
                                    {
                                        fflush(stdin);
                                        printf("1.Occupation\nPress correspinding digit\t:");
                                        scanf("%c",&ans2);
                                        if(ans2=='1'){bg_sub_search(bg,OCC,NONE);}
                                        else {  printf("Wrong Input.....Please Try again:\n:)");}
                                    }
                                    else if(status==SEX&&bg!=NULL)
                                    {
                                        fflush(stdin);
                                        printf("1.Sex\nPress correspinding digit\t:");
                                        scanf("%c",&ans2);
                                        if(ans2=='1') {bg_sub_search(bg,SEX,NONE);}
                                       else {printf("Wrong Input.......Please Try again:\n:)");}

                                    }
                                     else {system("cls"); printf("\n\n**********We were delighted to  help you!:)\t*****\n");return ;}
                                }

                                else {printf("Wrong Input.......Please Try again:\n:)");}
                    }else if (status==NONE){system("cls"); printf("Sorry.Thats it what we could do to you!\n\nAnyways,we were delighted to  help you!:)\t*****\n");return ;}

                    else {system("cls");printf("\nThank You for your time .We were delighted to help you:)");return;}

                            }
                            else {system("cls"); printf("No Results!\n\n**********We were delighted to  help you!:)\t*****\n");return ;}

    }
    else if(type==SEX)
    {
        CHECKPOINT3: while(1){
                        printf("Search for which GENDER individuals\n1.MALE\t2.FEMALE\nENTER CORRESPONDING NOUMBER\n");
                        fflush(stdin);//do for combinations
                        scanf("%c",&choice);
                        if(choice=='1') {bg=subseq_search_from_bg(bg,"masculine.txt",SEX);break;}
                        if(choice=='2') {bg=subseq_search_from_bg(bg,"feminine.txt",SEX);break;}
                        else printf("Incorrect Choice.Please Try Again\n");
                            }

                    if(bg!=NULL){
                             printf("press -5 to get details of all listed persons\n");
                             scanf("%d",&ser);
                             if(ser==-5)
                                {

                                 node* root=(node*)malloc(sizeof(node));
                                 fp=fopen("aadhar.txt","r");  //make_tree()
                                 fread(root,sizeof(node),1,fp);
                                 create_tree(root);
                                 fclose(fp);
                                 system("cls");
                                 for(num=0;num<bg->size;num++) {search_by_aadhar(root,bg[num].aadhar_no);}
                                 printf("press 0 to go back to search different GENDER individuals again\nPress -1 to go to main menu:\npress 2 to continue further searchingin previously obtained results:");
                                scanf("%d",&ans);if(ans==-1){system("cls");printf("\n\n**********We were delighted to  help you!:)\t*****\nThank you.");return;}if(ans==0)goto  CHECKPOINT3;
                                }

                            else if(ser==-1){system("cls");printf("\n\n**********We were delighted to  help you!:)\t*****\ngood luck\n");return;}
                            else if((ser)>0){
                                node* root=(node*)malloc(sizeof(node));
                                fp=fopen("aadhar.txt","r");  //make_tree()
                                fread(root,sizeof(node),1,fp);
                                create_tree(root);
                                fclose(fp);
                                system("cls");
                                search_by_aadhar(root,bg[ser-1].aadhar_no);
                                printf("press 0 to go back to search different GENDER individuals again\nPress -1 to go to main menu:\npress 2 to continue further searchingin previously obtained results:");
                                scanf("%d",&ans);if(ans==-1){system("cls");printf("\n\n**********We were delighted to  help you!:)\t*****\nThank you.");return;}if(ans==0)goto  CHECKPOINT3;
                                        }
                                        if(status!=NONE){
                            if(ans==2||ser==0)
                            {
                                  if(status==OCC_AOR&&bg!=NULL)
                                  {
                                     fflush(stdin);
                                     printf("1.Occupation\n2.Area Of Residence\nPress corresponding digit\t:");
                                     scanf("%c",&ans2);
                                     if(ans2=='1'){bg_sub_search(bg,OCC,AOR);}
                                     else if(ans2=='2') {bg_sub_search(bg,AOR,OCC);}
                                     else {printf("wrong inputPlease Try Again:)\n\n");}
                                 }

                                 else if(status==OCC&&bg!=NULL)
                                {
                                     fflush(stdin);
                                     printf("1.Occupation\nPress correspinding digit\t:");
                                     scanf("%c",&ans2);
                                     if(ans2=='1') {bg_sub_search(bg,OCC,NONE);}
                                     else {printf("Wrong Input.Please Try Again:)\n\n");}

                                }

                                else if(status==AOR&&bg!=NULL)
                                    {
                                      fflush(stdin);
                                      printf("1.Area Of Residence\nPress correspinding digit\t:");
                                      scanf("%c",&ans2);
                                      if(ans2=='1'){ bg_sub_search(bg,AOR,NONE);}
                                    }
                                else {system("cls"); printf("\n\n**********We were delighted to  help you!:)\t*****\n");return ;}

                            }
                            else {printf("Wrong Input.Please Try Again:)\n\n");}
                    }
                else{system("cls"); printf("\nThank You for your time .We were delighted to help you:)");return;}
            }else if (status==NONE){system("cls"); printf("Sorry.Thats it what we could do to you!\n\nAnyways,we were delighted to  help you!:)\t*****\n");return ;}
            else{system("cls"); printf("No Resutls\N\nThank You for your time .We were delighted to help you:)");return;}
  }
}
void aor_sub_search(area_of_resid* aor,int type,int status)
{

    char ch;
    int ser,ans,num;
    node* root=NULL;
    char choice;
    char ans2;
     if(type==BG)
    {
                 CHECKPOINT1:   while(1){
                        printf("Search for which blood group indiviuals?\n1.A+\t2.A-\t3.B+\t4.B-\t5.O+\t6.O-\t7.AB+\t8.AB-\n");
                        fflush(stdin);//do for combinations
                        scanf("%c",&choice);
                        if(choice=='1') {aor=subseq_search_from_aor(aor,"A_pos.txt",BG);break;}
                        if(choice=='2') {aor=subseq_search_from_aor(aor,"A_neg.txt",BG);break;}
                        if(choice=='3') {aor=subseq_search_from_aor(aor,"B_pos.txt",BG);break;}
                        if(choice=='4') {aor=subseq_search_from_aor(aor,"B_neg.txt",BG);break;}
                        if(choice=='5') {aor=subseq_search_from_aor(aor,"O_pos.txt",BG);break;}
                        if(choice=='6') {aor=subseq_search_from_aor(aor,"O_neg.txt",BG);break;}
                        if(choice=='7') {aor=subseq_search_from_aor(aor,"AB_pos.txt",BG);break;}
                        if(choice=='8') {aor=subseq_search_from_aor(aor,"AB_neg.txt",BG);break;}
                        else printf("Incorrect Choice.$$$$Please Try Again\n");
                        }
            if(aor!=NULL){
                             printf("press -5 to get details of all listed persons\n");
                             printf("type the serial no to get details of a PARTICULAR person :\nAre you even more keen interested further search in obtained results??[yes:press 0]\nreturn to main menu type-1\n]");
                         scanf("%d",&ser);if(ser==-5)
                            {

                                node* root=(node*)malloc(sizeof(node));
                                fp=fopen("aadhar.txt","r");  //make_tree()
                                fread(root,sizeof(node),1,fp);
                                create_tree(root);
                                fclose(fp);
                                system("cls");
                                for(num=0;num<aor->size;num++) {search_by_aadhar(root,aor[num].aadhar_no);}
                                printf("press 0 to go back to search different BLOOD GROUP again\nPress -1 to go to main menu:\npress 2 to continue further searchingin previously obtained results:");
                                scanf("%d",&ans);if(ans==-1){system("cls");printf("\n\n**********We were delighted to  help you!:)\t*****\nThank you.");return;}if(ans==0)goto CHECKPOINT1;


                            }
                            else if(ser==-1){system("cls");printf("\n\n**********We were delighted to  help you!:)\t*****\ngood luck\n");return;}
                            else if((ser)>0){
                                    node* root=(node*)malloc(sizeof(node));
                                    fp=fopen("aadhar.txt","r");  //make_tree()
                                    fread(root,sizeof(node),1,fp);
                                    create_tree(root);
                                    fclose(fp);
                                    system("cls");
                                    search_by_aadhar(root,aor[ser-1].aadhar_no);
                                    printf("press 0 to go back to search different BLOOD GROUP individuals again\nPress -1 to go to main menu:\npress 2 to continue further searchingin previously obtained results:");
                                    scanf("%d",&ans);if(ans==-1){system("cls");printf("\n\n**********We were delighted to  help you!:)\t*****\nThank you.");return;}if(ans==0)goto CHECKPOINT1;
                                            }
                                             if(status!=NONE){

                            if(ans==2||ser==0)
                            {
                                if(status==SEX_OCC&&aor!=NULL)
                                    {
                                        printf("1.Occupation\n2.Sex\nPress correspinding digit\t:");
                                        fflush(stdin);
                                        scanf("%c",&ans2);
                                        if(ans2=='1')
                                        {aor_sub_search(aor,OCC,SEX);}
                                        else if(ans2=='2')aor_sub_search(aor,SEX,OCC);
                                        else {printf("Incorrect input.Please try again:)");}
                                    }
                                else if(status==OCC&&aor!=NULL)
                                    {
                                     fflush(stdin);
                                    printf("1.Occupation\nPress correspinding digit\t:");
                                    scanf("%c",&ans2);
                                    if(ans2=='1')   {aor_sub_search(aor,OCC,NONE);}
                                     else {printf("Incorrect input.Please Try Again:)");}
                                    }
                                else if(status==SEX&&aor!=NULL)
                                    {
                                         fflush(stdin);
                                        printf("1.Sex\nPress correspinding digit\t:");
                                        scanf("%c",&ans2);
                                        if(ans2=='1'){aor_sub_search(aor,SEX,NONE);}
                                        else printf("Incorrect input.Please Try again");
                                    }
                            }
                        else printf("incorrect input\Please TRy again:)");

                }
                else if (status==NONE){system("cls"); printf("Sorry.Thats it what we could do to you!\n\nAnyways,we were delighted to  help you!:)\t*****\n");return ;}else { system("cls");printf("Thank You for your time .We were delighted to help you:)");return;}
            }
            else { system("cls");printf("No Results\n\nThank You for your time .We were delighted to help you:)");return;}
    }
     if(type==OCC)
    {
           CHECKPOINT2: while(1){
                            printf("Search for which Profession/Occupation individuals?\n\n:1.Medical_Service(Doctor/Nurse,etc)\t2.Engineer\t3.Government Service\t4.Teacher");
                            printf("5.Lawyer\t6.Self_Employed\t7.Housewife\t8.Unemployed\t9.Student\t10.Others\n\nENTER CORRESPONDING NOUMBER\n");
                            fflush(stdin);//do for combinations
                            scanf("%c",&choice);
                            if(choice=='1') {aor=subseq_search_from_aor(aor,"Medical_Service.txt",OCC);break;}
                            if(choice=='2') {aor=subseq_search_from_aor(aor,"Engineer.txt",OCC);break;}
                            if(choice=='3') {aor=subseq_search_from_aor(aor,"Government Service.txt",OCC);break;}
                            if(choice=='4') {aor=subseq_search_from_aor(aor,"Teacher.txt",OCC);break;}
                            if(choice=='5') {aor=subseq_search_from_aor(aor,"Lawyer.txt",OCC);break;}
                            if(choice=='6') {aor=subseq_search_from_aor(aor,"Self_Employed.txt",OCC);break;}
                            if(choice=='7') {aor=subseq_search_from_aor(aor,"Housewife.txt",OCC);break;}
                            if(choice=='8') {aor=subseq_search_from_aor(aor,"Unemployed.txt",OCC);break;}
                            if(choice=='9') {aor=subseq_search_from_aor(aor,"Student.txt",OCC);break;}
                            if(choice=='10') {aor=subseq_search_from_aor(aor,"Others.txt",OCC);break;}
                            else printf("Incorrect Choice.Please Try Again\n");
                        }
                      if(aor!=NULL){
                            printf("press -5 to get details of all listed persons\n");
                             printf("type the serial no to get details of a PARTICULAR person :\nAre you even more keen interested further search in obtained results??[yes:press 0]\nreturn to main menu type-1\n]");
                            scanf("%d",&ser);
                            if(ser==-5)
                            {

                                node* root=(node*)malloc(sizeof(node));
                                fp=fopen("aadhar.txt","r");  //make_tree()
                                fread(root,sizeof(node),1,fp);
                                create_tree(root);
                                fclose(fp);
                                system("cls");
                                for(num=0;num<aor->size;num++) search_by_aadhar(root,aor[num].aadhar_no);
                                printf("press 0 to go back to search individuals with various OCCUPATIONS  again\nPress -1 to go to main menu:\npress 2 to continue further searchingin previously obtained results:");
                                scanf("%d",&ans);if(ans==-1){system("cls");printf("\n\n**********We were delighted to  help you!:)\t*****\nThank you.");return;}if(ans==0)goto CHECKPOINT2;
                            }
                            else if(ser==-1){system("cls");printf("\n\n**********We were delighted to  help you!:)\t*****\ngood luck\n");return;}
                            else if((ser)>0){
                                node* root=(node*)malloc(sizeof(node));
                                fp=fopen("aadhar.txt","r");  //make_tree()
                                fread(root,sizeof(node),1,fp);
                                create_tree(root);
                                fclose(fp);
                                system("cls");
                                search_by_aadhar(root,aor[ser-1].aadhar_no);
                                printf("press 0 to go back to search individuals with various OCCUPATIONS again\nPress -1 to go to main menu:\npress 2 to continue further searchingin previously obtained results:");
                                scanf("%d",&ans);if(ans==-1){system("cls");printf("\n\n**********We were delighted to  help you!:)\t*****\nThank you.");return;}if(ans==0)goto CHECKPOINT2;
                                }
                                 if(status!=NONE){
                            if(ans==2||ser==0)
                            {

                                if(status==SEX_BG&&aor!=NULL)

                                {

                                    printf("1.Blood Group\n2.Sex\nPress correspinding digit\t:");
                                    fflush(stdin);
                                    scanf("%c",&ans2);
                                    if(ans2=='1'){aor_sub_search(aor,BG,SEX);}
                                    else if(ans2=='2')  aor_sub_search(aor,SEX,BG);
                                    else {    printf("Incorrect input.Please try again:)");}
                                }
                                else if(status==BG&&aor!=NULL)
                                {
                                     fflush(stdin);
                                    printf("1.Blood Group\nPress correspinding digit\t:");
                                    scanf("%c",&ans2);
                                    if(ans2=='1')  {aor_sub_search(aor,BG,NONE);}
                                    else {printf("Incorrect input.Please Try Again:)");}
                                }
                                else if(status==SEX&&aor!=NULL)
                                    {
                                         fflush(stdin);
                                         printf("1.Sex\nPress correspinding digit\t:");
                                         scanf("%c",&ans2);
                                         if(ans2=='1') {aor_sub_search(aor,SEX,NONE);}
                                         else { printf("Incorrect input.Please Try again");}
                                    }
                                else {system("cls"); printf("\n\n**********We were delighted to  help you!:)\t*****\n");return ;}
                            }
                           else { printf("Incorrect input.Please Try again"); return ;}

                        }
                        else if (status==NONE){system("cls"); printf("Sorry.Thats it what we could do to you!\n\nAnyways,we were delighted to  help you!:)\t*****\n");return ;}
                        else {system("cls"); printf("Thank You for your time .We were delighted to help you:)");return;}
                      }
                      else {system("cls"); printf("No Results.\n\nThank You for your time .We were delighted to help you:)");return;}
    }
    else if(type==SEX)
    {
      CHECKPOINT3: while(1){
                    printf("Search for which GENDER individuals\n1.MALE\t2.FEMALE\nENTER CORRESPONDING NOUMBER\n");
                    fflush(stdin);//do for combinations
                    scanf("%c",&choice);
                    if(choice=='1') {aor=subseq_search_from_aor(aor,"masculine.txt",SEX);break;}
                    if(choice=='2') {aor=subseq_search_from_aor(aor,"feminine.txt",SEX);break;}
                    else printf("Incorrect Choice.Please Try Again\n");
                    }

            if(aor!=NULL)
            {
                        printf("press -5 to get details of all listed persons\n");
                        printf("type the serial no to get details of a PARTICULAR person :\nAre you even more keen interested further search in obtained results??[yes:press 0]\nreturn to main menu type-1\n]");
                        scanf("%d",&ser);
                        if(ser==-5)
                        {
                            node* root=(node*)malloc(sizeof(node));
                            fp=fopen("aadhar.txt","r");  //make_tree()
                            fread(root,sizeof(node),1,fp);
                            create_tree(root);
                            fclose(fp);
                            system("cls");
                            for(num=0;num<aor->size;num++) {search_by_aadhar(root,aor[num].aadhar_no);}
                            printf("press 0 to go back to search GENDER individuals again\nPress -1 to go to main menu:\npress 2 to continue further searchingin previously obtained results:");
                            scanf("%d",&ans);if(ans==-1){system("cls");printf("\n\n**********We were delighted to  help you!:)\t*****\nThank you.");return;}if(ans==0)goto CHECKPOINT3;
                        }
                        else if(ser==-1){system("cls");printf("\n\n**********We were delighted to  help you!:)\t*****\ngood luck\n");return;}
                        else if((ser)>0){
                            node* root=(node*)malloc(sizeof(node));
                            fp=fopen("aadhar.txt","r");  //make_tree()
                            fread(root,sizeof(node),1,fp);
                            create_tree(root);
                            fclose(fp);
                            system("cls");
                            search_by_aadhar(root,aor[ser-1].aadhar_no);
                            printf("press 0 to go back to search GENDER individuals again\nPress -1 to go to main menu:\npress 2 to continue further searchingin previously obtained results:");
                            scanf("%d",&ans);if(ans==-1){system("cls");printf("\n\n**********We were delighted to  help you!:)\t*****\nThank you.");return;}if(ans==0)goto CHECKPOINT3;
                            }
                            if(status!=NONE){
                        if(ans==2||ser==0)
                        {
                            if(status==OCC_BG&&aor!=NULL)

                                {
                                     fflush(stdin);
                                    printf("1.Blood Group\n2.Occupation\nPress corresponding digit\t:");
                                    scanf("%c",&ans2);
                                    if(ans2=='1'){aor_sub_search(aor,BG,OCC);}
                                    else if(ans2=='2')   {aor_sub_search(aor,OCC,BG);}
                                    else { printf("wrong inputPlease Try Again:)\n\n");}

                                }
                            else if(status==BG&&aor!=NULL)
                                {
                                     fflush(stdin);
                                     printf("1.Blood Group\nPress correspinding digit\t:");
                                     scanf("%c",&ans2);
                                     if(ans2=='1')        {aor_sub_search(aor,BG,NONE);}
                                        else { printf("Wrong Input.Please Try Again:)\n\n");}
                                }
                            else if(status==OCC&&aor!=NULL)
                                    {
                                         fflush(stdin);
                                         printf("1.Occupation\nPress correspinding digit\t:");
                                        scanf("%c",&ans2);
                                        if(ans2=='1')  { aor_sub_search(aor,OCC,NONE);}
                                       else { printf("Wrong Input.Please Try Again:)\n\n");}
                                    }
                              else {system("cls"); printf("\n\n**********We were delighted to  help you!:)\t*****\n");return ;}


                        }
                        else { printf("Wrong Input.Please Try Again:)\n\n");  return ;}
                    }
                    else if (status==NONE){system("cls"); printf("Sorry.Thats it what we could do to you!\n\nAnyways,we were delighted to  help you!:)\t*****\n");return ;}
                   else{system("cls"); printf("\nThank You for your time .We were delighted to help you:)");return;}
            }
            else{system("cls"); printf("No Results!\n\n\nThank You for your time .We were delighted to help you:)");return;}
    }

}

void occ_sub_search(occupation* ocp,int type,int status)
{
    char ch;
    int ser,ans,num;
    node* root=NULL;
    char choice;
    char ans2;
     if(type==BG)
    {
        CHECKPOINT1: while(1){
                            printf("Search for which blood group indiviuals?\n1.A+\t2.A-\t3.B+\t4.B-\t5.O+\t6.O-\t7.AB+\t8.AB-\n");
                            fflush(stdin);//do for combinations
                            scanf("%c",&choice);
                            if(choice=='1') {ocp=subseq_search_from_occ(ocp,"A_pos.txt",BG);break;}
                            if(choice=='2') {ocp=subseq_search_from_occ(ocp,"A_neg.txt",BG);break;}
                            if(choice=='3') {ocp=subseq_search_from_occ(ocp,"B_pos.txt",BG);break;}
                            if(choice=='4') {ocp=subseq_search_from_occ(ocp,"B_neg.txt",BG);break;}
                            if(choice=='5') {ocp=subseq_search_from_occ(ocp,"O_pos.txt",BG);break;}
                            if(choice=='6') {ocp=subseq_search_from_occ(ocp,"O_neg.txt",BG);break;}
                            if(choice=='7') {ocp=subseq_search_from_occ(ocp,"AB_pos.txt",BG);break;}
                            if(choice=='8') {ocp=subseq_search_from_occ(ocp,"AB_neg.txt",BG);break;}
                            else printf("Incorrect Choice.$$$$Please Try Again\n");
                            }
                    if(ocp!=NULL){
                           // fflush("stdin"); what happened???
                             printf("press -5 to get details of all listed persons\n");
                             printf("type the serial no to get details of a PARTICULAR person :\nAre you even more keen interested further search in obtained results??[yes:press 0]\nreturn to main menu type-1\n]");
                            scanf("%d",&ser);

                            if(ser==-5)
                            {
                                node* root=(node*)malloc(sizeof(node));
                                fp=fopen("aadhar.txt","r");  //make_tree()
                                fread(root,sizeof(node),1,fp);
                                create_tree(root);
                                fclose(fp);
                                system("cls");
                                for(num=0;num<ocp->size;num++){search_by_aadhar(root,ocp[num].aadhar_no);}
                                printf("press 0 to go back to search BLOOD GROUP individuals again\nPress -1 to go to main menu:\npress 2 to continue further searchingin previously obtained results:");
                                scanf("%d",&ans);if(ans==-1){system("cls");printf("\n\n**********We were delighted to  help you!:)\t*****\nThank you.");return;}if(ans==0)goto CHECKPOINT1;
                            }
                            else if(ser==-1){system("cls");printf("\n\n**********We were delighted to  help you!:)\t*****\ngood luck\n");return;}
                            else if((ser)>0){
                                node* root=(node*)malloc(sizeof(node));
                                fp=fopen("aadhar.txt","r");  //make_tree()
                                fread(root,sizeof(node),1,fp);
                                create_tree(root);
                                fclose(fp);
                                system("cls");
                                search_by_aadhar(root,ocp[ser-1].aadhar_no);
                                printf("press 0 to go back to search BLOOD GROUP individuals again\nPress -1 to go to main menu:\npress 2 to continue further searchingin previously obtained results:");
                                scanf("%d",&ans);if(ans==-1){system("cls");printf("\n\n**********We were delighted to  help you!:)\t*****\nThank you.");return;}if(ans==0)goto CHECKPOINT1;
                                }
                                if(status!=NONE){
                            if(ans==2||ser==0)
                            {
                                if(status==SEX_AOR&&ocp!=NULL)
                                {
                                     printf("1.Area of Residence\n2.Sex\nPress correspinding digit\t:");
                                     fflush(stdin);
                                     scanf("%c",&ans2);
                                     if(ans2=='1')  {occ_sub_search(ocp,AOR,SEX);}
                                     else if(ans2=='2')occ_sub_search(ocp,SEX,AOR);
                                    else {printf("Incorrect input.Please try again:)");}
                                }
                                else if(status==AOR&&ocp!=NULL)
                                {
                                     fflush(stdin);
                                    printf("1.Area of Residence\nPress correspinding digit\t:");
                                    scanf("%c",&ans2);
                                    if(ans2=='1'){occ_sub_search(ocp,AOR,NONE);}
                                    else { printf("Incorrect input.Please Try Again:)");}
                                }
                               else if(status==SEX&&ocp!=NULL)
                                {
                                    fflush(stdin);
                                    printf("1.Sex\nPress correspinding digit\t:");
                                    scanf("%c",&ans2);
                                    if(ans2=='1'){occ_sub_search(ocp,SEX,NONE);}
                                    else {   printf("Incorrect input.Please Try again");}
                                }
                                else {system("cls"); printf("\n\n**********We were delighted to  help you!:)\t*****\n");return ;}
                            }

                            else {system("cls"); printf("\n\nIncorrect input*We were delighted to  help you!:)\t*****\n");return ;}

                        }
                        else if (status==NONE){system("cls"); printf("Sorry.Thats it what we could do to you!\n\nAnyways,we were delighted to  help you!:)\t*****\n");return ;}
                        else { system("cls");printf("Thank You for your time .We were delighted to help you:)");return;}
                        }
                        else if (ocp==NULL) printf("No Results!\n");

    }

     else if(type==AOR)
    {
    CHECKPOINT2: while(1){
                        printf("Search for which area individuals\n1.Ramnagar\t2.East Delhi3.South Delhi.4.North Delhi\t5.West Delhi\t6.Shantinagar\t7.Gopalnagar\t8.Shivajipeth\n\nENTER CORRESPONDING NOUMBER\n");
                        fflush(stdin);//do for combinations
                        scanf("%c",&choice);
                        if(choice=='1') {ocp=subseq_search_from_occ(ocp,"Ramnagar.txt",AOR);break;}
                        if(choice=='2') {ocp=subseq_search_from_occ(ocp,"East_Delhi.txt",AOR);break;}
                        if(choice=='3') {ocp=subseq_search_from_occ(ocp,"South_Delhi.txt",AOR);break;}
                        if(choice=='4') {ocp=subseq_search_from_occ(ocp,"North_Delhi.txt",AOR);break;}
                        if(choice=='5') {ocp=subseq_search_from_occ(ocp,"West_Delhi.txt",AOR);break;}
                        if(choice=='6') {ocp=subseq_search_from_occ(ocp,"Shantinagar.txt",AOR);break;}
                        if(choice=='7') {ocp=subseq_search_from_occ(ocp,"Gopalnagar.txt",AOR);break;}
                        if(choice=='8') {ocp=subseq_search_from_occ(ocp,"Shivajipeth.txt",AOR);break;}
                        else printf("Incorrect Choice.Please Try Again\n");
                        }

             if(ocp!=NULL){
                             printf("press -5 to get details of all listed persons\n");
                             printf("type the serial no to get details of a PARTICULAR person :\nAre you even more keen interested further search in obtained results??[yes:press 0]\nreturn to main menu type-1\n]");
                            scanf("%d",&ser);
                            if(ser==-5)
                                {

                                    node* root=(node*)malloc(sizeof(node));
                                    fp=fopen("aadhar.txt","r");  //make_tree()
                                    fread(root,sizeof(node),1,fp);
                                    create_tree(root);
                                    fclose(fp);
                                    system("cls");
                                    for(num=0;num<ocp->size;num++){search_by_aadhar(root,ocp[num].aadhar_no);}
                                    printf("press 0 to go back to search RESIDENTS again\nPress -1 to go to main menu:\npress 2 to continue further searchingin previously obtained results:");
                                    scanf("%d",&ans);if(ans==-1){system("cls");printf("\n\n**********We were delighted to  help you!:)\t*****\nThank you.");return;}if(ans==0)goto CHECKPOINT2;
                                }
                            else if(ser==-1){system("cls");printf("\n\n**********We were delighted to  help you!:)\t*****\ngood luck\n");return;}
                            else if((ser)>0){
                                  node* root=(node*)malloc(sizeof(node));
                                  fp=fopen("aadhar.txt","r");  //make_tree()
                                    fread(root,sizeof(node),1,fp);
                                    create_tree(root);
                                    fclose(fp);
                                    system("cls");
                                    search_by_aadhar(root,ocp[ser-1].aadhar_no);
                                    printf("press 0 to go back to search RESIDENTS  individuals again\nPress -1 to go to main menu:\npress 2 to continue further searchingin previously obtained results:");
                                    scanf("%d",&ans);if(ans==-1){system("cls");printf("\n\n**********We were delighted to  help you!:)\t*****\nThank you.");return;}if(ans==0)goto CHECKPOINT2;

                                         }    if(status!=NONE){
                        if(ans==2||ser==0)
                        {
                              if(status==SEX_BG&&ocp!=NULL)
                                {
                                     fflush(stdin);
                                    printf("1.Blood Group\n2.Sex\nPress corresponding digit\t:");
                                    scanf("%c",&ans2);
                                    if(ans2=='1')  {occ_sub_search(ocp,BG,SEX);}
                                    else if(ans2=='2'){occ_sub_search(ocp,SEX,BG);}
                                    else printf("Wrong Input....Please try again\n:)");
                                }
                                else if(status==BG&&ocp!=NULL)
                                {
                                     fflush(stdin);
                                    printf("1.Blood Group\nPress correspinding digit\t:");
                                    scanf("%c",&ans2);
                                    if(ans2=='1') {occ_sub_search(ocp,BG,NONE);}

                                }
                                else if(status==SEX&&ocp!=NULL)
                                    {
                                        fflush(stdin);
                                        printf("1.Sex\nPress correspinding digit\t:");
                                       scanf("%c",&ans2);
                                        if(ans2=='1') {occ_sub_search(ocp,SEX,NONE);}
                                         else  printf("Wrong Input.....Please Try again:\n:)");
                                    }
                                else {system("cls"); printf("\n\n**********We were delighted to  help you!:)\t*****\n");return ;}

                        }
                          else  printf("Wrong Input.....Please Try again:\n:)");

              }
              else if (status==NONE){system("cls"); printf("Sorry.Thats it what we could do to you!\n\nAnyways,we were delighted to  help you!:)\t*****\n");return ;}
                  else {system("cls");printf("\nThank You for your time .We were delighted to help you:)");return;}
            }
            else {system("cls");printf("No Results!\n\nThank You for your time .We were delighted to help you:)");return;}
    }
        else if(type==SEX)
        {
            while(1){
                 printf("Search for which GENDER individuals\n1.MALE\t2.FEMALE\nENTER CORRESPONDING NOUMBER\n");
                 fflush(stdin);//do for combinations
                 scanf("%c",&choice);
                 CHECKPOINT3:   if(choice=='1') {ocp=subseq_search_from_occ(ocp,"masculine.txt",SEX);break;}
                                if(choice=='2') {ocp=subseq_search_from_occ(ocp,"feminine.txt",SEX);break;}
                                else printf("Incorrect Choice.Please Try Again\n");
                }
            if (ocp!=NULL){
                        printf("press -5 to get details of all listed persons\n");
                        printf("type the serial no to get details of a PARTICULAR person :\nAre you even more keen interested further search in obtained results??[yes:press 0]\nreturn to main menu type-1\n]");
                        scanf("%d",&ser);
                        if(ser==-5)
                            {
                                  node* root=(node*)malloc(sizeof(node));
                                fp=fopen("aadhar.txt","r");  //make_tree()
                                fread(root,sizeof(node),1,fp);
                                create_tree(root);
                                fclose(fp);
                                system("cls");
                                for(num=0;num<ocp->size;num++)search_by_aadhar(root,ocp[num].aadhar_no);
                                printf("press 0 to go back to search GENDER individuals again\nPress -1 to go to main menu:\npress 2 to continue further searchingin previously obtained results:");
                                scanf("%d",&ans);if(ans==-1){system("cls");printf("\n\n**********We were delighted to  help you!:)\t*****\nThank you.");return;}if(ans==0)goto CHECKPOINT3;
                            }
                        else if(ser==-1){system("cls");printf("\n\n**********We were delighted to  help you!:)\t*****\ngood luck\n");return;}
                        else if((ser)>0){
                                node* root=(node*)malloc(sizeof(node));
                                fp=fopen("aadhar.txt","r");  //make_tree()
                                fread(root,sizeof(node),1,fp);
                                create_tree(root);
                                fclose(fp);
                                system("cls");
                                search_by_aadhar(root,ocp[ser-1].aadhar_no);
                                printf("press 0 to go back to search GENDER individuals again\nPress -1 to go to main menu:\npress 2 to continue further searchingin previously obtained results:");
                                scanf("%d",&ans);if(ans==-1){system("cls");printf("\n\n**********We were delighted to  help you!:)\t*****\nThank you.");return;}if(ans==0)goto CHECKPOINT3;
                        }
                          if(status!=NONE){

                        if(ans==2||ser==0)
                        {
                            if(status==BG_AOR&&ocp!=NULL)
                            {
                                    fflush(stdin);
                                    printf("1.Blood Group\n2.Area Of Residence\nPress corresponding digit\t:");
                                    scanf("%c",&ans2);
                                    if(ans2=='1') {occ_sub_search(ocp,BG,AOR);}
                                    else if(ans2=='2'){occ_sub_search(ocp,AOR,BG);}
                                    else { printf("wrong inputPlease Try Again:)\n\n");}


                            }
                            else if(status==BG&&ocp!=NULL)
                            {
                                    fflush(stdin);
                                    printf("1.Blood Group\nPress correspinding digit\t:");
                                    scanf("%c",&ans2);
                                    if(ans2=='1') {occ_sub_search(ocp,BG,NONE);}
                                    else { printf("Wrong Input.Please Try Again:)\n\n");}
                            }
                            else if(status==AOR&&ocp!=NULL)
                            {
                                    fflush(stdin);
                                    printf("1.Area Of Residence\nPress correspinding digit\t:");
                                    scanf("%c",&ans2);
                                    if(ans2=='1'){ occ_sub_search(ocp,AOR,NONE);}
                                    else {printf("Wrong Input.Please Try Again:)\n\n");}

                            }
                            else {system("cls"); printf("\n\n**********We were delighted to  help you!:)\t*****\n");return ;}
                        }
                        else {printf("Wrong Input.Please Try Again:)\n\n");}

                }
                else if (status==NONE){system("cls"); printf("Sorry.Thats it what we could do to you!\n\nAnyways,we were delighted to  help you!:)\t*****\n");return ;} else{system("cls"); printf("\nThank You for your time .We were delighted to help you:)");return;}
            }
            else {system("cls"); printf("No Results!\n\nThank You for your time .We were delighted to help you:)\n");return;}


    }

}



main()
{
    int i=0,j,aadhar_no,ans;
    char c;//take ans alwys in charachter
    char name[30];
  while(1)
    {
        printf("_________________________________________________________________\n");
        for(j=0;j<3;j++) printf("|\t\t\t\t\t\t\t\t!\n");
        printf("!\t\tWELCOME TO AADHAR MANAGEMENT SYSTEM\t\t!\n");
        for(j=3;j<5;j++)printf("|\t\t\t\t\t\t\t\t!\n");
        //printf("\n\n\t\tWELCOME TO AADHAR MANAGEMENT SYSTEM\n\n");
         printf("!_______________________________________________________________!\n");



        printf("\nEnter Choice:\n");
        printf("\t\t1.Add a new Aadhar(from beginning!!WARNING!!THIS WILL ESARE ALL PRE-EXISTING DATA.)\n");
        printf("\t\t2.Display Deteils in Inorder\n");
       // printf("\t\t3.Delete.\n");
        printf("\t\t3.Wanna Search???\n");
        printf("\t\t4.Append: to add more data.\n");
       // printf("\t\t6.Display Names accoding to name_id");
        printf("\t\tPress 0 to exit\n\n\n\n\n\n\n");
        scanf("%d",&ans);
        system("cls");
         if(ans==1)
          {
               system("cls");
             node* root=NULL;
            root=add(root,1);
          }
        else if(ans==2) //What if empty?
        {
             system("cls");
            fp=fopen("aadhar.txt","r");
            node* rut=(node*)malloc(sizeof(node));
            fread(rut,sizeof(node),1,fp);
            display(rut);
            fclose(fp);

/*if(c==1)
                printf("Empty queue\n\n");*/
        }
    //else if(ans==3)    del(node);
        else if (ans==3)
        {
             system("cls");
            char choice;
             int i=0,ans1;
             char ans2;
             gender* sex=NULL;
             fflush(stdin);
            printf("Search by:\t1.Name\t2.Aadhar_no3.Blood_group.\t4.Occupation\t5.Adress\t6.Sex\n");
            scanf("%c",&choice);
             unsigned long int aadhar_no;
             occupation* ocp=NULL;
             area_of_resid* aor=NULL;
             blood_grp* bg=NULL;
            if(choice=='1'){
                    system("cls");
                search_by_name();
            }
            else if(choice=='2'){
               // unsigned long int aadhar_no;
               system("cls");
               fflush(stdin);
                printf("Enter Aadhar No:");
                scanf("%ld",&aadhar_no);
                node* root=(node*)malloc(sizeof(node));
                fp=fopen("aadhar.txt","r");  //make_tree()
                fread(root,sizeof(node),1,fp);
                create_tree(root);
                fclose(fp);
                system("cls");
                search_by_aadhar(root,aadhar_no);

            }
            else if(choice=='3'){
                while(1){
                        system("cls");
                printf("Search for which blood group indiviuals?\n1.A+\t2.A-\t3.B+\t4.B-\t5.O+\t6.O-\t7.AB+\t8.AB-\n");
                fflush(stdin);//do for combinations
                scanf("%c",&choice);
                if(choice=='1') {bg=search_by_blood_grp("A_pos.txt");break;}
                if(choice=='2') {bg=search_by_blood_grp("A_neg.txt");break;}
                if(choice=='3') {bg=search_by_blood_grp("B_pos.txt");break;}
                if(choice=='4') {bg=search_by_blood_grp("B_neg.txt");break;}
                if(choice=='5') {bg=search_by_blood_grp("O_pos.txt");break;}
                if(choice=='6') {bg=search_by_blood_grp("O_neg.txt");break;}
                if(choice=='7') {bg=search_by_blood_grp("AB_pos.txt");break;}
                if(choice=='8') {bg=search_by_blood_grp("AB_neg.txt");break;}
                else printf("Incorrect Choice.Please Try Again\n");
                }
                system("cls");
                    printf("***********************************************************************\n");
                                printf("***********************************************************************\n");
                                printf("_______________________________________________________________________\n");
                 printf("\t\t\tTotal Results:%d\n\n",bg->size);
                while(i<bg->size)
                {
                printf("%s %s %d %s\n",bg[i].f_name,bg[i].l_name,(bg[i].aadhar_no),bg[i].blood_group); //Why?
                i++;
                }printf("***********************************************************************\n");
                                printf("***********************************************************************\n");
                                printf("_______________________________________________________________________\n");
                 printf("Are you keen interested further search in obtained results[y/n]");
               scanf("%c",&ans2);
               if(ans2=='y'||ans2=='Y')
               {

                   printf("1.Occupation\n2.Area of Residence\n3.Sex\nPress correspinding digit\t:");
                   fflush(stdin);
                   scanf("%c",&ans2);
                   if(ans2=='1')
                   {
                      {bg_sub_search(bg,OCC,SEX_AOR);}
                   }
                   else if(ans2=='2')
                   {
                      {bg_sub_search(bg,AOR,SEX_OCC);}
                   }
                   else if(ans2=='3')
                   {
                      {bg_sub_search(bg,SEX,OCC_AOR);}
                   }
                   else printf("Wrong input.Please Try Again\n");

               }
               else if (ans2=='n'||ans2=='N') {system("cls");printf("Okay!thank you for your time .!\n happy to help you:)");}
               else {system("cls"); printf("Wrong input.Please Try Again\n");}

               fflush(stdin);
                }


             else if(choice=='4'){
                 while(1){system("cls");
               printf("Search for which Profession/Occupation individuals?\n\n:1.Medical_Service(Doctor/Nurse,etc)\t2.Engineer\t3.Government Service\t4.Teacher");
               printf("5.Lawyer\t6.Self_Employed\t7.Housewife\t8.Unemployed\t9.Student\t10.Others\n\nENTER CORRESPONDING NOUMBER\n");
                fflush(stdin);//do for combinations
                //int ll???
                scanf("%c",&choice);
                if(choice=='1') {ocp=search_by_occupation("Medical_Service.txt");break;}
                if(choice=='2') {ocp=search_by_occupation("Engineer.txt");break;}
                if(choice=='3') {ocp=search_by_occupation("Government Service.txt");break;}
                if(choice=='4') {ocp=search_by_occupation("Teacher.txt");break;}
                if(choice=='5') {ocp=search_by_occupation("Lawyer.txt");break;}
                if(choice=='6') {ocp=search_by_occupation("Self_Employed.txt");break;}
                if(choice=='7') {ocp=search_by_occupation("Housewife.txt");break;}
                if(choice=='8') {ocp=search_by_occupation("Unemployed.txt");break;}
                if(choice=='9') {ocp=search_by_occupation("Student.txt");break;}
                 if(choice=='10') {ocp=search_by_occupation("Others.txt");break;}
                else printf("Incorrect Choice.Please Try Again\n");
                }

                //subseq_search_from_occ(ocp,"A_pos.txt");
                system("cls");printf("***********************************************************************\n");
                                printf("***********************************************************************\n");
                                printf("_______________________________________________________________________\n");
                printf("\t\t\tTotal Results:%d\n\n",ocp->size);i=0;
                //bg=search_by_blood_grp("A_pos.txt");
                while(i<ocp->size)
                {
                printf("%s %s %d %s\n",ocp[i].f_name,ocp[i].l_name,ocp[i].aadhar_no,ocp[i].occupation); //
                i++;
                }printf("***********************************************************************\n");
                                printf("***********************************************************************\n");
                                printf("_______________________________________________________________________\n");
                //printf("\n\n\n");*/
               //printf("Do ");
              //  scanf("&d",&l);
               printf("Are you keen interested further search in obtained results[y/n]");
               scanf("%c",&ans2);
               if(ans2=='y'||ans2=='Y')
               {
                   printf("1.Blood_group\n2.Area of Residence\n3.Sex\nPress correspinding digit\t:");
                   fflush(stdin);
                   scanf("%c",&ans2);
                   if(ans2=='1')
                   {
                      {occ_sub_search(ocp,BG,SEX_AOR);}
                   }
                   else if(ans2=='2')
                   {
                      {occ_sub_search(ocp,AOR,SEX_BG);}
                   }
                   else if(ans2=='3')
                   {
                      {occ_sub_search(ocp,SEX,BG_AOR);}
                   }
                   else printf("Wrong input.Please Try Again\n");

               }
               else if (ans2=='n'||ans2=='N') {system("cls");printf("Okay!thank you for your time .!\n happy to help you:)");}
               else { system("cls");printf("Wrong input.Please Try Again\n");}

               fflush(stdin);
               }




           //break;
             else if(choice=='5'){
                        while(1){system("cls");
                 printf("Search for which area individuals\n1.Ramnagar\t2.East Delhi3.South Delhi.4.North Delhi\t5.West Delhi\t6.Shantinagar\t7.Gopalnagar\t8.Shivajipeth\n\nENTER CORRESPONDING NOUMBER\n");
            //what if wrong input
                fflush(stdin);//do for combinations
                scanf("%c",&choice);
                if(choice=='1') {aor=search_by_area_of_resid("Ramnagar.txt");break;}
                if(choice=='2') {aor=search_by_area_of_resid("East_Delhi.txt");break;}
                if(choice=='3') {aor=search_by_area_of_resid("South_Delhi.txt");break;}
                if(choice=='4') {aor=search_by_area_of_resid("North_Delhi.txt");break;}
                if(choice=='5') {aor=search_by_area_of_resid("West_Delhi.txt");break;}
                if(choice=='6') {aor=search_by_area_of_resid("Shantinagar.txt");break;}
                if(choice=='7') {aor=search_by_area_of_resid("Gopalnagar.txt");break;}
                if(choice=='8') {aor=search_by_area_of_resid("Shivajipeth.txt");break;}
                else     printf("Incorrect Choice,DUDE!!  :/  \nPlease Try Again\n\n\n");
                }
                system("cls"); printf("***********************************************************************\n");
                                printf("***********************************************************************\n");
                                printf("_______________________________________________________________________\n");
                                 printf("\t\t\tTotal Results:%d\n\n",aor->size);
                while(i<aor->size)
                {
                printf("%s %s %d %s\n",aor[i].f_name,aor[i].l_name,aor[i].aadhar_no,aor[i].area_of_resid);
                i++; //

                }    printf("_______________________________________________________________________\n");
                printf("***********************************************************************\n");
                                printf("***********************************************************************\n");

                 printf("Are you keen interested further search in obtained results[y/n]");
               scanf("%c",&ans2);
               if(ans2=='y'||ans2=='Y')
               {
                   printf("1.Blood_group\n2.Occupation\n3.Sex\nPress correspinding digit\t:");
                   fflush(stdin);
                   scanf("%c",&ans2);
                   if(ans2=='1')
                   {
                      {aor_sub_search(aor,BG,SEX_OCC);}
                   }
                   else if(ans2=='2')
                   {
                      {aor_sub_search(aor,OCC,SEX_BG);}
                   }
                   else if(ans2=='3')
                   {
                      {aor_sub_search(aor,SEX,OCC_BG);}
                   }
                   else printf("Wrong input.Please Try Again\n");

               }
               else if (ans2=='n'||ans2=='N') {system("cls");printf("Okay!thank you for your time .!\n happy to help you:)");}
               else { system("cls");printf("Wrong input.Please Try Again\n");}

               fflush(stdin);
             }



                else if(choice=='6'){
                            while(1){system("cls");
                     printf("Search for which gender individuals\n1.MALE\t2.FEMALE?\n");
                     fflush(stdin);//do for combinations
                scanf("%c",&choice);
                if(choice=='1') {sex=search_by_sex("masculine.txt");break;}
                else if(choice=='2') {sex=search_by_sex("feminine.txt");break;}
                 else printf("Incorrect Choice.Please Try Again\n");}
                    system("cls");printf("***********************************************************************\n");
                                printf("***********************************************************************\n");
                                printf("_______________________________________________________________________\n");
               printf("\t\t\tTotal Results:%d\n\n",sex->size);
                while(i<sex->size)
                {
                printf("%s %s %d %c\n",sex[i].f_name,sex[i].l_name,sex[i].aadhar_no,sex[i].sex); //
                i++;
                }printf("***********************************************************************\n");
                                printf("***********************************************************************\n");
                                printf("_______________________________________________________________________\n");

                }


            }

        else if(ans==4)
        {

            append(); //USE RETURN NODE* BRING IN BUFFER ,PERFORM OPERATIONS,SAVE FINALLY.
        }
        else if(ans==6) //What if Empty?
        {
            fp2=fopen("names.txt","r");
            node2* rut2=(node2*)malloc(sizeof(node2));
            fread(rut2,sizeof(node2),1,fp2);
            system("cls");
            display2(rut2);
            fclose(fp2);
        }
        else if(ans)  printf("Incorrect Choice,DUDE!!  :/  \nPlease Try Again\n\n\n");


         else if(ans==0)
        {
            system("cls");
            printf("Had a Great time\nGood luck\nGoodBye\n\n\n");
            printf("\n\nDevelopers:\n1)Deepankar Umare\n2)Vijit Saxena\n3)Vikash Kumar Sah\n4)Suraj Barfa\n\n");
            getch();
            break;
        }
       //sleep(3000);

}
}





