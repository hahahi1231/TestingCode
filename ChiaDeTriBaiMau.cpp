#include<bits/stdc++.h>
using namespace std;


//tao mang random
void sinh(int *&a, int &n){
	cout<<"\n so phan tu mang can sinh:"; cin>>n;
	a= new int[n];
	for(int i=0; i<n; i++)
		a[i] =rand()%501;// %501 de mang co gia tri nho de~ tinh toan
}
// in ra mang da tao
void in(int *&a, int &n){
	cout<<"\n noi dung mang:\n";
	for(int i=0; i<n; i++) cout<<a[i] <<" ";
}
//Sap xep mang tang dan
void Merge(int*&a, int L, int R){
	        int m= (L+R)/2; // chia mang thanh 2 phan
			int i=L, j=m+1, v=0;  
            int *kq= new int[R-L+1]; // mang ket qua tam chua day tang dan
            //Thuat toan chia de tri
             while (i<=m && j<=R)
                if(a[i]<=a[j]) { 
					kq[v]=a[i];
					i++;
					v++;
				 }  
				else {
				 kq[v] =a[j]; 
				 v++; 
				 j++;
				}
				
             while (i<=m) { 
				 kq[v]=a[i]; 
					 i++; 
					 v++;
			 }
             while (j<=R ) { 
			 	kq[v] =a[j]; 
					 v++; 
					 j++;
			 }
            		 i=L;  
				//Sao chep mang *kq sang mang *a
			 	for(j=0; j<v; j++)  
			 		a[i++] = kq[j];
        
}

void Mergesort(int*&a, int L, int R){
	if(L<R)
	{
		int m=(L+R)/2;
		Mergesort(a,  L, m);
		Mergesort(a,  m+1, R);
		Merge(a, L, R);
	}

}

int main(){
	int *a, n;
	sinh(a,n);
	in(a,n);
	Mergesort(a, 0, n-1);
	cout<<"\n day sau khi sap xep:\n";
	in(a,n);
	
}

