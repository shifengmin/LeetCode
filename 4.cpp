class Solution {
public:
    double findKthInArrs(int l1,int r1,int l2,int r2,int k,vector<int>& nums1, vector<int>& nums2){
		if(l1>r1){
            return nums2[l2+k-1];
        }
        if(l2>r2){
            return nums1[l1+k-1];
        }
        if(k==r1+r2-l1-l2+2) return max(nums1[r1],nums2[r2]);
 		if(k==1) return min(nums1[l1],nums2[l2]);
 		if(l1==r1){
 		    if(nums1[r1] >= nums2[l2+k-1]) return nums2[l2+k-1];
 		    else if(nums1[r1] >= nums2[l2+k-2]) return nums1[r1];
 		    else return nums2[l2+k-2];
		}
		if(l2==r2){
		    if(nums2[r2] >= nums1[l1+k-1]) return nums1[l1+k-1];
			else if(nums2[r2] >= nums1[l1+k-2]) return nums2[r2];
			else return nums1[l1+k-2];
		}
 		int m1 = l1+r1 >> 1;
        int m2 = l2+r2 >> 1;
        if(nums1[m1]<=nums2[m2]){
            if(k<=m1-l1+1){
                return findKthInArrs(l1,m1,l2,m2,k,nums1,nums2);
            }else if(k<=m1-l1+1+m2-l2+1){
                return findKthInArrs(l1,r1,l2,m2,k,nums1,nums2);
            }else{
                return findKthInArrs(m1+1,r1,l2,r2,k-(m1-l1+1),nums1,nums2);
            }
        }else{
            if(k<=m2-l2+1){
                return findKthInArrs(l1,m1,l2,m2,k,nums1,nums2);
            }else if(k<=m1-l1+1+m2-l2+1){
                return findKthInArrs(l1,m1,l2,r2,k,nums1,nums2);
            }else{
                return findKthInArrs(l1,r1,m2+1,r2,k-(m2-l2+1),nums1,nums2);
            }
        }
    }
    
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        int L = n+m;
        if(L&1) return findKthInArrs(0,n-1,0,m-1,L/2+1,nums1,nums2);
        else return (findKthInArrs(0,n-1,0,m-1,L/2+1,nums1,nums2)+findKthInArrs(0,n-1,0,m-1,L/2,nums1,nums2))*0.5;
    }
};
