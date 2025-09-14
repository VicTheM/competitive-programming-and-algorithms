import java.util.*;
import java.io.*;

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    static PrintWriter out = new PrintWriter(System.out);
    
    // Fast input methods
    static String next() throws IOException {
        while (st == null || !st.hasMoreTokens()) {
            st = new StringTokenizer(br.readLine());
        }
        return st.nextToken();
    }
    
    static int nextInt() throws IOException {
        return Integer.parseInt(next());
    }
    
    static long nextLong() throws IOException {
        return Long.parseLong(next());
    }
    
    static double nextDouble() throws IOException {
        return Double.parseDouble(next());
    }
    
    // Constants
    static final int MOD = 1000000007;
    static final int INF = Integer.MAX_VALUE;
    static final long LINF = Long.MAX_VALUE;
    
    static void solve() throws IOException {
        // Your solution here
        
    }
    
    public static void main(String[] args) throws IOException {
        int t = 1;
        // t = nextInt(); // Uncomment for multiple test cases
        
        while (t-- > 0) {
            solve();
        }
        
        out.close();
    }
}