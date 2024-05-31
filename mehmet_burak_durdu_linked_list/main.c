#include <stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node* next;
};

struct node* head;

//dugum olusturucu
struct node* node_adder(int data)
{
  struct node* key = (struct node*)malloc(sizeof(struct node));
  key->data = data;
  key->next = NULL;
  printf("dugum olusturuluyor...\n");
  return(key);
}

//dugum dolasici
void list_iterator()
{
    printf("\n");
    struct node* temp = head;
    while(temp != NULL)
    {
        printf(" %d ", temp->data);
        temp = temp->next;
    }
    printf("\ndolasma bitti lutfen yeni islem yapiniz");
}

//basa ekler
void insert_first(int data)
{
    struct node* new_node = node_adder(data);
    if(head == NULL)
    {
        head = new_node;
        return(printf("ilk kez eleman ekleniyor...\n"));
    }

    else
    {
        struct node* temp = head;
        head = new_node;
        head->next = temp;

    }
}

//sona ekler
void insert_last(int data)
{
    struct node* new_node = node_adder(data);
    if(head == NULL)
    {
        head = new_node;
        return(printf("ilk kez eleman ekleniyor...\n"));
    }
    else
    {
        struct node* temp = head;
        while(temp->next != NULL)
            temp = temp->next;
        temp->next = new_node;

    }

}
//sondakini siler
void delete_last()
{
    if(head == NULL)
        return(printf("liste bos oldugu icin eleman silme islemi yapilamaz!\n"));


    else if(head != NULL && head->next == NULL)
        head = NULL;
    else
    {
        struct node* temp = head;
        while(temp->next->next != NULL)
            temp = temp->next;
        free(temp->next);
        temp->next = NULL;
    }
}
//basakini siler
void delete_first()
{
    if(head == NULL)
        return(printf("liste bos oldugu icin eleman silme islemi yapilamaz!\n"));;

    if(head->next == NULL)
        head = NULL;
    else
    {
        struct node* sec_node = head->next;
        head = sec_node;
    }
}

void select()
{
    int choose, value;
    printf("\n1- Sona Eleman Ekle\n2- Basa Eleman Ekle\n3- Sondan Eleman Sil\n4- Bastan Eleman Sil\nYapmak istediginiz islemi Secin.... ");
    scanf("%d", &choose);
    switch(choose)
    {
        case 1:
            printf("\nEklenilecek sayiyi giriniz:");
            scanf("%d", &value);
            insert_last(value);
            printf("%d sona eklendi",value);
            break;

        case 2:
            printf("\nEklemek istediginiz sayiyi girin: ");
            scanf("%d", &value);
            insert_first(value);
            printf("%d basa eklendi",value);
            break;

        case 3:
            delete_last();
            printf("sondaki item silindi");
            break;

        case 4:
            delete_first();
            printf("bastaki item silindi");
            break;
    }
    list_iterator();
}

int main()
{
    while(1)
        select();
}

/*
KAYNAKCA:
list_iterator ve node_adder kismini aldigim kaynaklar
https://www.learn-c.org/en/Linked_lists
https://www.programiz.com/dsa/linked-list-operations
https://www.mshowto.org/veri-yapilari-2-bagli-listeler.html#close
https://www.log2base2.com/data-structures/linked-list/inserting-a-node-at-the-end-of-a-linked-list.html
*/
