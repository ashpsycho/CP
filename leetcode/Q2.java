public class Solution {
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        ListNode ans=new ListNode(0),tail=new ListNode(0),head1=l1,head2=l2;
        int carry=0,curr,i;
        for(i=0;head1!=null || head2!=null;i++){
            if(head1==null){
                curr=head2.val+carry;
            }
            else if(head2==null){
                curr=head1.val+carry;   
            }
            else{
                curr=carry+head1.val+head2.val;
            }
            carry=(curr/10);
            curr=(curr%10);
            if(i==0)ans=tail=new ListNode(curr);
            else{
                tail.next=new ListNode(curr);
                tail=tail.next;
            }
            if(head1!=null)head1=head1.next;
            if(head2!=null)head2=head2.next;
        }
        if(carry==1){
            tail.next=new ListNode(1);
            tail=tail.next;
        }
        return ans;
    }
}