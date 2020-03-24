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
	for(int i=0; i<n; i++) 
		cout<<a[i] <<" ";
}
// Sap xep
void Merge(int*&a, int L, int R){
// L, R la bien trai va bien phai cua mang
	    int m= (L+R)/2; // chia mang thanh 2 phan
			int i=L, j=m+1, v=0;  
            int *kq= new int[R-L+1]; // mang ket qua tam chua day tang dan
            
             while (i<=m && j<=R)
                if(a[i]<=a[j]) { 
				kq[v]=a[i]; // Neu a[i] < a[j] thi copy phan tu ben trai vao mang tam
					i++; // Vi tri phan tu tiep theo cua mang
					v++;
				}  
			  else { // Neu a[i] > a[j] thi copy phan tu ben phai vao mang tam
				 kq[v] =a[j]; 
					 v++; 
					 j++; // Vi tri phan tu tiep theo cua mang
				}
				
             while (i<=m) { 
				 kq[v]=a[i]; 
					 i++; 
					 v++;
			 }
	     // Nguoc lai dua cac phan tu con lai cua mang con ben phai vao mang tam
             while (j<=R ) { 
			 	kq[v] =a[j]; 
					 v++; 
					 j++;
			 }
            		 i=L;  
			 	for(j=0; j<v; j++)  
			 		a[i++] = kq[j];
        
}
void Mergesort(int*&a, int L, int R){
	if(L<R)
	{
		int m=(L+R)/2;
		Mergesort(a,  L, m); // Goi de quy mang con ben trai
		Mergesort(a,  m+1, R);// Goi de quy mang con ben phai
		Merge(a, L, R);// Goi ham so sanh hai mang con
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

