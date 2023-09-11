/*每组输入数据占1行,每行数据的开始是2个整数n(0<=n<=100)和m(0<=m<=100),分别表示集合A和集合B的元素个数，然后紧跟着n+m个元素，前面n个元素属于集合A，其余的
属于集合B. 每个元素为不超出int范围的整数,元素之间有一个空格隔开.如果n=0并且m=0表示输入的结束，不做处理。
Output
针对每组数据输出一行数据,表示A-B的结果,如果结果为空集合，则输出“NULL”,否则从小到大输出结果,为了简化问题，每个元素后面跟一个空格.
*/
#include<stdio.h>
#include<string.h>
void selectsort(int arr[],int n);
int main(void)
{
	int arr[2][105],output[105],i,j,count,n,m,temp;
	while(scanf("%d %d",&n,&m)==2&&(n!=0||m!=0)){//这个条件好坑…… 
		memset(arr,0,sizeof(int));
		count=0;
		for(i=0;i<n;i++){//不重复地读入A集合 
			scanf("%d",&temp);
			for(j=0;j<i;j++){
				if(arr[1][j]==temp){
					break;
				}
			}
			if(i==j){
				arr[1][i]=temp;
				arr[0][i]=1;
			}
		}
		for(i=0;i<m;i++){//去掉A集合中B集合的元素 
			scanf("%d",&temp);
			for(j=0;j<n;j++){
				if(temp==arr[1][j]){
					arr[0][j]=0;
					break;
				}
			}
		}
		for(i=0;i<n;i++){
			if(arr[0][i]==1){//将集合中剩下的元素输入到output 
				output[count]=arr[1][i];
				count++;//count表示个数 
			}
		}
		selectsort(output,count);
		for(i=0;i<count;i++)//输出output 
			printf("%d ",output[i]);
		if(count==0)
			printf("NULL\n");
		else
			printf("\n");
	}
	return 0;
}
void selectsort(int arr[],int n)
{
	int i,j,loc,temp;
	for(i=0;i<n-1;i++){
		for(j=i+1,temp=arr[j],loc=j;j<n;j++){
			if(temp>arr[j]){
				temp=arr[j];
				loc=j;
			}
		}
		if(arr[i]>arr[loc]){
			arr[loc]=arr[i];
			arr[i]=temp;
		}
	}
	return;
}
