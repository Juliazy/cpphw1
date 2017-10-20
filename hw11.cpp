#include <iostream>


public class TreeNode {
	private Object obj;
	private TreeNode parent;
	private TreeNode left;
	private TreeNode right;
	//重写构造方法
	public TreeNode(Object obj){
		this.obj=obj;
	}
	
	public Object getObj() {
		return obj;
	}
	public void setObj(Object obj) {
		this.obj = obj;
	}
	public TreeNode getParent() {
		return parent;
	}
	public void setParent(TreeNode parent) {
		this.parent = parent;
	}
	public TreeNode getLeft() {
		return left;
	}
	public void setLeft(TreeNode left) {
		this.left = left;
	}
	public TreeNode getRight() {
		return right;
	}
	public void setRight(TreeNode right) {
		this.right = right;
	}
	
}

/**
	 * 将一个数插入二叉树中
	 * @param node	在这个结点下插入新的结点
	 * @param value	
*/
	public void addToTree(TreeNode node, int value){  
		if((Integer)node.getObj()>value){
			//当前结点的值比value大，则成为其左子结点
			if(node.getLeft()!=null){
				//看这个结点的左子结点是否存在，如果存在
				node=node.getLeft();
				//递归调用该方法
				addToTree(node, value); 
			}else{
				//不存在
				TreeNode TNode=new TreeNode(value); 
				TNode.setParent(node);   
                node.setLeft(TNode); 
			}	
		}
		else{
			//当前结点的值比value小，则成为其右子结点
			if (node.getRight() != null) { 
				//看这个结点的右子结点是否存在，如果存在
				node = node.getRight();   
				addToTree(node, value);   
            }else{   
            	//不存在
            	TreeNode TNode=new TreeNode(value);  
            	TNode.setParent(node);   
                node.setRight(TNode);   
            }   
		}
	}

/**
	 * 将一个数组转化为一个二叉树
	 * @param array
	 * @return
	 */
	public TreeNode arrayToTree(int [] array){
		if(array.length == 0){   
            throw new RuntimeException("数组长度为0，没有元素用来建树！！！");   
        } 
		//把第一个元素变成根结点
        int first = array[0];   
        root = new TreeNode(first);   
        for (int i = 1; i < array.length; i++) {   
        	addToTree(root, array[i]); 
        }   
		return root;
	}

int main()
{
	int tree[100];
	for (int i=0; i<100; i++)
	{
		tree[i]=i+1;
	}
	arrayToTree(tree);
	
	return 0;
}