#include<stdio.h>
int main(){
	int n, choice;
	int max, secdMax;
	int min, secdMin;
	int pos, value;
	int check;
	int size;
	int arr[50]; 
	printf("\tMENU\n");
	printf("1. Nhap so phan tu va gia tri phan tu trong mang\n");
	printf("2. In mang ra man hinh\n");
	printf("3. Dem so luong so hoan hao\n");
	printf("4. Dem so luong so nguyen to\n");
	printf("5. Tim gia tri lon thu 2\n");
	printf("6. Tim gia tri nho thu 2\n");
	printf("7. Them phan tu tai vi tri\n");
	printf("8. Xoa phan tu tai vi tri\n");
	printf("9. Sap xep mang tang dan(thao tac chen)\n");
	printf("10. Sap xep mang theo giam dan(thao tac chen)\n");
	printf("11. Tim kiem phan tu trong mang(tim kiem nhi phan)\n");
	printf("12. Xoa cac phan tu trung lap va in cac phan tu duy nhat\n");
	printf("13. Sap xep va hien thi so chan dung truoc, so le dung sau\n");
	printf("14. Dao nguoc mang\n");
	printf("15. Thoat\n");
	do{
		printf("Nhap lua chon cua ban: ");
		scanf("%d", &choice);
		if(choice<1||choice>15){
			printf("Nhap lua chon hop le: ");
			scanf("%d", &choice);
		}
		switch(choice){
			case 1:
				printf("Nhap so phan tu ban muon: ");
				scanf("%d", &n);
				if(n<1||n>50){
					printf("Nhap lai so phan tu hop le: ");
					scanf("%d",&n);
				}
				for(int i=0;i<n;i++){
					printf("Nhap phan tu arr[%d]: ", i);
					scanf("%d", &arr[i]);
				}
				break;
			case 2:
				printf("Mang: \n");
				for(int i=0;i<n;i++){
					printf("arr[%d] = %d\n", i, arr[i]);
				}
				break;
			case 3:
				if(size>0){
					int check = 0;
					int sum;
					for(int i=0;i<size;i++){
						for(int j=1;j<=arr[i]/2;j++){
							if(arr[i]%j==0){
								sum+=j;
							}
						}
						if(sum==arr[i]){
							check++;
						}
					}
					printf("So luong cac so hoan hao co trong mang la : %d ",check);
				}else{
					printf("Khong ton tai mang !!!!");
				}
				printf("\n"); 
				break;
			case 4:
				if(size>0){
					int numbercheck=0;
					for(int i=0;i<size;i++){
						numbercheck++;
						if(arr[i]==2){
							numbercheck--;
						}
						for(int j=2;j*j<arr[i];j++){
							if(arr[i]%j==0){
								numbercheck--;
								break;
							}
						}
					}
					printf("So luong cac so nguyen to co trong mang la %d ",numbercheck);
				}else{
					printf("Khong ton tai mang !!!!");
				}
				printf("\n");				
				break;
			case 5:
				max=arr[0];
				secdMax=arr[0];
				for(int i=1;i<n;i++){
					if(arr[i]>max){
						max=arr[i];
					}
				}
				for(int i=1;i<n;i++){
					if(arr[i]>secdMax&&arr[i]!=max){
						secdMax=arr[i];
					}
				}
				printf("So lon thu 2 trong mang la: %d\n", secdMax);
				break;
			case 6:
				min=0;
				secdMin=0;
				if(arr[0]<arr[1]){
					min=arr[0];
					secdMin=arr[1];
				} else {
					min=arr[1];
					secdMin=arr[0];
				}
				for(int i=2;i<n;i++){
					if (arr[i]<min){
						secdMin=min;
						min=arr[i];
					} else if(arr[i]<secdMin&&arr[i]!=min){
						secdMin=arr[i];
					}
				}
				printf("So nho thu 2 trong mang la: %d\n", secdMin);
				break;
			case 7:
				printf("Moi ban nhap vao phan tu muon them: ");
				scanf("%d", &value);
				printf("Moi ban nhap vao vi tri muon them: ");
				scanf("%d", &pos);
				if(pos<=0||pos>n){
					printf("Moi ban nhap lai vi tri hop le: ");
					scanf("%d",&pos);
				}
				for(int i=n;i>pos;i--){
					arr[i]=arr[i-1];
				}
				arr[pos]=value;
				n++;
				break;
			case 8:
				printf("Moi ban nhap vao vi tri phan tu muon xoa: ");
				scanf("%d", &pos);
				if(pos<0||pos>n){
					printf("Moi ban nhap lai vi tri hop le: ");
					scanf("%d", &pos);
				}
				for (int i=pos;i<n-1;i++){
					arr[i]=arr[i+1];
				}
				n--;
				break;
			case 9:
				if(size>0){
					for(int i=0;i<size-1;i++){
						for(int j=0;j<size-i-1;j++){
							if(arr[j]>arr[j+1]){
								int temp = arr[j];
								arr[j] = arr[j+1];
								arr[j+1] = temp;
							}	
						}
					}
					printf("Mang sau khi duoc sap xep theo thu tu tang dan : ");
					for(int i=0;i<size;i++){
						printf("\tarr[%d]=%d",i,arr[i]);
					}
				}else{
					printf("Khong ton tai mang !!!!");
				}
				printf("\n");					
				break;
			case 10:
				if(size>0){
					for(int i=0;i<size-1;i++){
						for(int j=0;j<size-i-1;j++){
							if(arr[i]<arr[j+1]){
								int temp2 = arr[i];
								arr[i] = arr[j+1];
								arr[j+1] = temp2;
							}
						}
					}
					printf("Mang sau khi duoc sap xep theo thu tu giam dan : ");
					for(int i=0;i<size;i++){
						printf("\tarr[%d]=%d",i,arr[i]);
					}
				}else{
					printf("Khong ton tai mang !!!!");
				}
				printf("\n");					
				break;
			case 11:
				if(size>0){
					int search=0;
					printf("Ban muon tim gia tri phan tu nao trong mang : ");
					scanf("%d",&value);
					for(int i=0;i<size;i++){
						if(arr[i]=value){
							search=i;
						}
					}
					if(search>0){
						printf("gia tri phan tu ban muon tim o vi tri : %d",search);
					}else{
						printf("Khong ton tai gia tri trong mang ");
					}
				}else{
					printf("Khong ton tai mang");
				}
				printf("\n");					
				break;
			case 12:
				printf("Cac phan tu doc nhat la: ");
				for(int i=0;i<n;i++){
					check=0;
					for(int j=i+1;j<n;j++){
						if(arr[i]==arr[j]){
							check++;
							for (int k=j;k<n-1;k++){
								arr[k]=arr[k+1];
							}
							n--;
						}
					}
					if(check==0){
						printf("%d\t", arr[i]);
					}
				}
				printf("\n");
				break;
			case 13:
				if(size>0){
					printf("Mang sau khi sap xep theo yeu cau : ");
					for(int i=0;i<size;i++){
						if(arr[i]%2==0){
							printf("%3d",arr[i]);
							}
						}
					for(int i=0;i<size;i++){
						if(arr[i]%2!=0){
							printf("%3d",arr[i]);
						}
					}
				}else{
					printf("Khong ton tai mang !!!!");
				}
				printf("\n");
				break;
			case 14:
				if(size>0){
					for(int i=size-1;i>=0;i--){
						printf("%3d",arr[i]);
					}
				}else{
					printf("Khong ton tai mang !!!!");
				}
				printf("\n");
				break;				
			case 15:
				return 0;
				break;
		}
	} while(1);
return 0;
}
