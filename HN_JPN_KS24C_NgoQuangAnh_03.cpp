#include<stdio.h>

int main(){
	int n;
	int arr[100];
	int choice;
	do{
		printf("\n --- MENU --- \n");
		printf("1. Nhap so phan tu va gia tri cho mang \n");
		printf("2. In ra cac phan tu gia tri trong mang \n");
		printf("3. Dem so luong cac so nguyen to trong mang \n");
		printf("4. Tim gia tri nho thu 2 trong mang \n");
		printf("5. Them vao vi tri moi trong mang do nguoi dung nhap vao \n");
		printf("6. Xoa mot vi tri cu the \n");
		printf("7. Sap xep mang theo vi tri giam dan (Insertion sort) \n");
		printf("8. Tim kiem phan tu trong mang (Binary search) \n");
		printf("9. Xoa toan bo phan tu trung lap trong mang va hien thi toan bo phan tu doc nhat trong mang \n");
		printf("10. Dao nguoc thu tu cac phan tu trong mang \n");
		printf("11. Thoat \n");
		printf("Nhap lua chon cua ban : ");
		scanf("%d",&choice);
		switch(choice){
			case 1 : {
				printf("Nhap so luong phan tu trong mang : ");
				scanf("%d",&n);
				if(n < 0 || n > 100){
					printf("Vui long nhap lai do dai mang tu 1 - 100");
					break;
				}
				for(int i = 0 ; i < n ; i++){
					printf("Nhap phan tu thu %d : ",i+1);
					scanf("%d",&arr[i]);
				}
				printf("Nhap thanh cong \n");
				break;
			}
			case 2 : {
				if(n < 0){
					printf("Vui long nhap mang \n");
					break;
				}
				printf("Mang da nhap la : ");
				for(int i = 0 ; i < n ; i++){
					printf("arr[%d] = %d ,",i,arr[i]);
				}
				printf("\n");
				break;
			}
			case 3 : {
				if(n < 0){
					printf("Vui long nhap mang \n");
					break;
				}
				int count = 0;
				for(int i = 0 ; i < n ; i++){
					int number = arr[i];
					int isPrime = 1;
					if(number < 2){
						isPrime = 0;
					}else{
						for(int i = 2 ; i*i <= number ; i++){
							if(number % i == 0){
								isPrime = 0;
								break;
							}
						}	
					}
					if(isPrime){
						count++;
					}
				}
				printf("So luong so nguyen to trong mang la : %d",count);
				break;
			}
			case 4 : {
				if(n < 2){
					printf("Vui long nhap mang co it nhat 2 phan tu \n");
					break;
				}
				for(int i = 0 ; i < n ; i++){
					int key = arr[i];
					int j = i - 1;
					while(j > 0 && arr[j] > key){
						arr[j+1] = arr[j];
						j--;
					}
					arr[j+1] = key;
				}
				int min1 = arr[0];
				int min2 = -1;
				for(int i = 0 ; i < n ; i++){
					if(arr[i] != min1){
						min2 = arr[i];
						break;
					}
				}
				if(min2 == -1){
					printf("Khong co phan tu nho thu 2 \n");
				}else{
					printf("Phan tu nho thu 2 la : %d \n",min2);
				}
				break;
			}
			case 5 : {
				if(n < 0){
					printf("Vui long nhap mang \n");
					break;
				}
				int addValue , addIndex;
				printf("Nhap gia tri muon them vao : ");
				scanf("%d",&addValue);
				printf("Nhap vi tri muon them vao : ");
				scanf("%d",&addIndex);
				if(addIndex < 0 || addIndex > n){
					printf("Vui long nhap lai vi tri muon them \n");
					break;
				}
				for(int i = n ; i > addIndex ; i--){
					arr[i] = arr[i-1];
				}
				arr[addIndex] = addValue;
				n++;
				printf("Mang sau khi them la : ");
				for(int i = 0 ; i < n ; i++){
					printf("arr[%d] = %d ,",i+1,arr[i]);
				}
				break;
			}
			case 6 : {
				if(n < 0){
					printf("Vui long nhap mang \n");
					break;
				}
				int deleteIndex;
				printf("Nhap vi tri muon xoa : ");
				scanf("%d",&deleteIndex);
				if(deleteIndex < 0 || deleteIndex > n){
					printf("Vui long nhap lai vi tri muon xoa \n");
					break;
				}
				for(int i = deleteIndex ; i < n - 1 ; i++){
					arr[i] = arr[i+1];
				}
				n--;
				printf("Mang sau khi xoa la : ");
				for(int i = 0 ; i < n ; i++){
					printf("arr[%d] = %d ,",i+1,arr[i]);
				}
				break;
			}
			case 7 : {
				if(n < 0){
					printf("Vui long nhap mang \n");
					break;
				}
				for(int i = 1 ; i  < n ; i++){
					int key = arr[i];
					int j = i - 1;
					while(j >= 0 && arr[j] < key){
						arr[j+1] = arr[j];
						j--;
					}
					arr[j+1] = key;
				}
				printf("Mang sau khi sap xep la : ");
				for(int i = 0 ; i < n ; i++){
					printf("arr[%d] = %d ,",i+1,arr[i]);
				}
				break;
			}
			case 8 : {
				if(n < 0){
					printf("Vui long nhap mang \n");
					break;
				}
				for(int i = 1 ; i < n ; i++){
					int key = arr[i];
					int j = i - 1;
					while(j >= 0 && arr[j] > key){
						arr[j+1] = arr[j];
						j--;
					}
					arr[j+1] = key;
				}
				printf("Mang sau khi sap xep la : ");
				for(int i = 0 ; i < n ; i++){
					printf("%d \t",arr[i]);
				}
				printf("\n");
				int input;
				printf("Nhap gia tri muon tim kiem : ");
				scanf("%d",&input);
				int left = 0 , right = n - 1;
				int found = 0;
				while(left <= right){
					int mid = (left + right) / 2;
					if(arr[mid] == input){
						printf("Gia tri can tim nam o cac vi tri : ");
						int i = mid;
						while(i >= 0 && arr[i] == input){
							printf("%d ",i);
							i--;
						}
						i = mid + 1;
						while(i <= n && arr[i] == input){
							printf("%d ",i);
							i++;
						}
						printf("\n");
						found = 1;
						break;
					}else if(arr[mid] < input){
						left = mid + 1; 
					}else{
						right = mid - 1;
					}
				}
				if(!found){
					printf("Khong co gia tri can tim trong mang \n");
					break;
				}
				break;
			}
			case 9 : {
				break;
			}
			case 10 : {
				if(n < 0){
					printf("Vui long nhap mang \n");
					break;
				}
				int left = 0 , right = n - 1;
				while (left < right){
					int temp = arr[left];
					arr[left] = arr[right];
					arr[right] = temp;
					left++;
					right--;
				}
				printf("Mang sau khi hoan doi la : ");
				for(int i = 0 ; i < n ; i++){
					printf("%d \t",arr[i]);
				}
				break;
			}
			case 11 : {
				printf("Thoat chuong trinh...");
				break;
			}
			default : {
				printf("Vui long nhap lai tu 1 - 11");
				break;
			}
		}
	}while(choice!=11);
	return 0;
}
