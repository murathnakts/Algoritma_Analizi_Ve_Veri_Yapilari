#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
    };

struct node *head = NULL;

void listeyiYazdir(){
    system("cls");
    if(head==NULL){
        printf("Liste Bos\n\n");
        return;
    }
    struct node *temp = head;
    while(temp->next!=head){
        printf("%d->",temp->data);
        temp = temp->next;
    }
    printf("%d",temp->data);
    printf("\n\n");
    }

void basaEkle(int data){
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    if(head==NULL){
        temp->data = data;
        temp->next = temp;
    }else {
    struct node *temp2 = head;
    while(temp2->next != head){
        temp2 = temp2->next;
    }
        temp->data = data;
        temp->next = head;
        temp2->next = temp;
    }
    head = temp;

}

void sonaEkle(int data) {
    if(head==NULL){
        printf("Liste Bosken Sona Eleman Ekleyemezsiniz!\n");
        return;
    }
    struct node *temp2 = head;
    while(temp2->next != head){
        temp2 = temp2->next;
    }
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = data;
    temp->next = head;
    temp2->next = temp;
    printf("\n");
}

void ortayaEkle(int data,int index){
    if(head==NULL){
        printf("Liste Bosken Ortaya Eleman Ekleyemezsiniz!\n");
        return;
    }
    struct node *temp2 = head;
    while(temp2->data != index){
        if(temp2->next == head){
            return;
        }
        temp2 = temp2->next;
    }
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = data;
    temp->next = temp2->next;
    temp2->next = temp;
    printf("\n");
}

void elemanDuzenle(int data,int index){
    if(head==NULL){
        printf("Liste Bosken Eleman Duzenleyemezsiniz!\n");
        return;
    }
    struct node *temp = head;
    while(temp->data != index){
        if(temp->next == head){
            return;
        }
        temp = temp->next;
    }
    temp->data = data;
    printf("\n");
}

void elemanSil(int data){
    if(head==NULL){
        printf("Liste Bosken Eleman Silemezsiniz!\n");
        return;
    }
    struct node *temp = head;
    if(head->data == data){
            if(head->next == head){
                head = NULL;
                return;
            }
        struct node *temp2 = head;
        while(temp2->next != head){
            temp2 = temp2->next;
        }
        temp2->next = head->next;
        head = head->next;
        free(temp);

    }else {
        while(temp->next->data != data){
            if(temp->next == head){
                return;
            }
            temp = temp->next;
        }
        struct node *temp2 = temp->next;
        temp->next = temp2->next;
        free(temp2);
    }
}

void listeyiSil(){

    struct node *temp = head;
    struct node *temp2;

    while(head != NULL){
        temp2 = temp;
        temp = temp->next;
        elemanSil(temp2->data);
    }
}

void elemanSayisi(){
    int sayac = 0;
    if(head==NULL){
        printf("Eleman Sayisi 0\n\n");
        return;
    }
    struct node *temp = head;
    while(temp->next != head){
        temp = temp->next;
        sayac++;
    }
    sayac++;
    printf("Eleman Sayisi %d\n\n",sayac);
}




int main()
{
    int secim,data,index;
    listeyiYazdir();

    while(1){
        printf("1-Listenin Basina Eleman Ekleme\n");
        printf("2-Listenin Sonuna Eleman Ekleme\n");
        printf("3-Listenin Ortasina Eleman Ekleme\n");
        printf("4-Elemanlari Listele\n");
        printf("5-Eleman Duzenleme\n");
        printf("6-Listeden Eleman Silmek\n");
        printf("7-Listeyi Sil\n");
        printf("8-Listedeki Eleman Sayisi\n");
        printf("9-Programdan Cikma\n");
        printf("Seciminiz...\n");
        scanf("%d", &secim);
        printf("\n");

    switch(secim){
        case 1:
            printf("Lutfen Basa Eklemek Istediginiz Degeri Giriniz: ");
            scanf("%d", &data);
            basaEkle(data);
            listeyiYazdir();
            break;

        case 2:
            if(head==NULL){
                listeyiYazdir();
                break;
            }
            printf("Lutfen Sona Eklemek Istediginiz Degeri Giriniz: ");
            scanf("%d", &data);
            sonaEkle(data);
            listeyiYazdir();
            break;

        case 3:
            if(head==NULL){
                listeyiYazdir();
                break;
            }
            printf("Lutfen Eklemek Istediginiz Degeri Giriniz: ");
            scanf("%d", &data);
            printf("Lutfen Yanina Eklemek Istediginiz Sayiyi Giriniz: ");
            scanf("%d", &index);
            ortayaEkle(data,index);
            listeyiYazdir();
            break;

        case 4:
            listeyiYazdir();
            break;

        case 5:
            if(head==NULL){
                listeyiYazdir();
                break;
            }
            printf("Lutfen Eklemek Istediginiz Degeri Giriniz: ");
            scanf("%d", &data);
            printf("Lutfen Degistirmek Istediginiz Degeri Giriniz: ");
            scanf("%d", &index);
            elemanDuzenle(data,index);
            listeyiYazdir();
            break;

        case 6:
            if(head==NULL){
                listeyiYazdir();
                break;
            }
            printf("Lutfen Silmek istediginiz Elemanin Degerini Giriniz: ");
            scanf("%d",&data);
            elemanSil(data);
            listeyiYazdir();
            break;

        case 7:
            listeyiSil();
            listeyiYazdir();
            break;

        case 8:
            listeyiYazdir();
            elemanSayisi();
            break;

        case 9:
            exit(0);
        break;
        default: listeyiYazdir();
            }
        }
    }



