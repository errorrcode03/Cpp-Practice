#include<iostream>
#include<vector>
using namespace std ;
void segmentTree(vector<int>&arr,int indx ,int st , int end, vector<int>&tree){
	if(end==st){
	tree[indx]=arr[st];
	return ;}
    int mid =st+(end-st)/2;
    int left_tree=2*indx+1;
    int right_tree=2*indx+2;
    segmentTree(arr,left_tree,st,mid,tree);
    segmentTree(arr,right_tree,mid+1,end,tree);
        tree[indx]=tree[left_tree]+tree[right_tree];
}
void update(vector<int>&tree , int indx,int pos,int value,int st , int end){
	if(st==end){
	      tree[indx]=value;
		return ;
	}
	int mid=st+(end-st)/2;
	int left=indx*2+1;
	int right=indx*2+2;
	if(pos<=mid){
		update(tree,left,pos,value,st,mid);
	}
	else {
		update(tree,right,pos,value,mid+1,end);
	}
	tree[indx]=tree[right]+tree[left];
}
int query(vector<int>&tree, int root_indx  , int st , int end , pair<int,int>&p){
	if(p.second<st || p.first>end){
		return 0;
	}
	if(p.first<=st && p.second>=end){
		return tree[root_indx];
	}
	int left_ri=2*root_indx+1;
	int right_ri=2*root_indx+2;
	int mid= st+(end-st)/2;
	int leftsum=query(tree,left_ri, st,mid,p);
	int rightsum=query(tree,right_ri,mid+1,end , p );
	return rightsum+leftsum;
}
int main(){
	//segment tree
	 vector<int>arr={1,2,3,4};
	 int n=arr.size();
	 vector<int>tree(4*n,0);
	segmentTree(arr,0,0,n-1,tree);
	update(tree,0,1,2,0,n-1);
    pair<int,int>qu={0,2};
    cout<<query(tree,0,0,n-1,qu);
}