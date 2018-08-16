
import java.util.Scanner;
import java.util.Arrays;
import java.util.Vector;

class Graph
{
    private int n;
    private boolean mat[][];
    private boolean trans_mat[][];
    int color[],transpose_color[];
    Graph(int x)
    {
        n=x;
        color = new int[100];
		
		transpose_color = new int[100];
		
        mat=new boolean[n+1][n+1];
        
        trans_mat=new boolean[n+1][n+1];
        
        for (int i = 0; i <= x; i++)
		{
			color[i] = 0;
			transpose_color[i]=0;
		}
        
      
    }

    void set(int z1,int z2)
    {
        mat[z1][z2]=true;
        trans_mat[z2][z1] = true;
       
    }
    void set_color(int nd,int cl)
    {
    	color[nd] = cl;
    }
    void set_transcolor(int nd,int cl)
    {
    	transpose_color[nd] = cl;
    }

    boolean isAdjacent(int a,int b)
    {
        return mat[a][b];
    }
    boolean isAdjacent_transpose(int a,int b)
    {
        return trans_mat[a][b];
    }
    public int ret_color(int i)
	{
		return color[i];
	}
	public int ret_transcolor(int i)
	{
		return transpose_color[i];
	}

    int getNodes()
    {
        return n;
    }
    
    public String toString()
    {
        String output;
        output="Number of Nodes "+n+"\nThe Edges are:\n";
        for(int i=0;i<=n;i++)
        {
            for(int j=i+1;j<=n;j++)
            {
                if(mat[i][j]==true)
                    output=output+i+"-"+j+"\n";
            }
        }
        return output;
	}
}
class dfs
{
	Graph G1 ;
	int GREY,WHITE,BLACK;
	int sz;
	int in;
	
	Vector vec,vec2;
	private int top_array[];
	int scc_array[];
	dfs(Graph object,int z)
	{
		G1 = object;
		sz = z;
		in=0;
		
		scc_array = new int[z];
		
		vec = new Vector(z+1);
		
		vec2 = new Vector(z+1);
		
		top_array = new int [sz+1];
		
		GREY = 1;WHITE = 0;BLACK = 2;	
		
	}
	void top_sort(int p)
	{
		G1.set_color(p,1);
		for(int i=1;i<=sz;i++)
		{
			if(G1.isAdjacent(p,i)==true&& G1.ret_color(i)==0)
			{
				top_sort(i);
			}
		}
		
		G1.set_color(p,2);
		top_array[in++] = p;
		//vec2.add(p);
		
		
	}
	void print_topsort()
	{
		
		System.out.println("::Topological sort ::");
                System.out.println();
                for(int i=in-1;i>=0;i--)
			System.out.print(top_array[i] +" ");
                System.out.println();
	}
	Vector  ret_array()
	{
		return vec2;
	}
        int []return_array()
        {
            return  top_array;
        }
	int top_size()
	{
		return in;
	}
	
}
class SCC
{
	Graph grp; dfs DFS;
	int top_array[];
	Vector v,vec2;int sz; 
    int ar[];
	SCC(Graph g,dfs d,int nd)
	{
		grp = g; DFS = d;
		top_array = new int[DFS.top_size()];
		v = DFS.ret_array();
        ar  = DFS.return_array();
        sz = nd;
        vec2 = new Vector(sz+1) ;
	}
	void scc_check()
	{
		for(int i=DFS.top_size()-1;i>=0;i--)
		{ 
			clear();
			int t = ar[i];
			if(grp.ret_transcolor(t)==0)
			{
				dfs_check(t);
				scc_print();
			}
		}
	}
	void dfs_check(int p)
	{
		//System.out.println("dskf");
		grp.set_transcolor(p,1);
		for(int i=1;i<=sz;i++)
		{
			if(grp.isAdjacent_transpose(p,i)==true&& grp.ret_transcolor(i)==0)
			{
				dfs_check(i);
			}
		}
		
		grp.set_transcolor(p,2);
		
		vec2.add(p);
		
	}
	void scc_print()
	{
                System.out.println("Components:");
		for(int i=0;i<vec2.size();i++)
			System.out.print(vec2.elementAt(i)+" ");
		System.out.println();
		
	}
	void clear()
	{
		vec2.clear();
	}
}

public class Main {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		
		System.out.println("Input :");
        Scanner sc=new Scanner(System.in);
        System.out.println("Enter num of nodes and edges\n");
        int node=sc.nextInt();
        int edges=sc.nextInt();
        Graph graph = new Graph(node);
    
       
        for(int i=0 ;i<edges ;i++)
        {
           int x = sc.nextInt();
           int y = sc.nextInt();
           graph.set(x , y);
        }
        dfs object = new dfs(graph,node);
        for(int i=1;i<=node;i++)
        {
        	if(graph.ret_color(i)==0)
        	{
        		  object.top_sort(i);
        	}
        }
        object.print_topsort();
      
        SCC sc_ob = new SCC(graph,object,node) ;
        sc_ob.scc_check();

	}

}
