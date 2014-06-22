/***************************************************************************
 * Compilation: javac PercolationStats.java
 * Execution: java PercolationStats N T
 * Dependencies: Percolation.java StdOut.java StdRandom.java
 *
 * Runs a simulation of the Percolation problem T times with an N-by-N grid.
 *
 * ************************************************************************/

/**
 * The <tt>PercolationStats</tt> class runs a simulation on the Percolation
 * class.
 *
 * @author Michael Esses
 */
public class PercolationStats
{
    private int N;
    private int T;
    private double[] xi;

    /**
     * Performs T independent computational experients on an N-by-N grid.
     * @throws java.lang.IllegalArgumentException if N <= 0 or T <= 0.
     * @param N the length of the N-by-N grid
     * @param T the number of independent computational experiments
     */
    public PercolationStats(int N, int T)
    {
        if (N <= 0 || T <= 0) throw new IllegalArgumentException();
        
        xi = new double[T];
        this.N = N;
        this.T = T;

        for (int i = 0; i < T; i++)
        {
            simulate(i);
        }
    }

    /**
     * Sample mean of percoluation threshold
     */
    public double mean()
    {
        double sum = 0;
        for (double i : xi)
        {
            sum += i;
        }

        return sum / T;
    }

    /**
     * Sample standard deviation of percolution threshold
     */
    public double stddev()
    {
        if (T == 1)
        {
            return Double.NaN;
        }

        double mu = mean();
        double squares = 0;

        for (double i : xi)
        {
			squares += (i - mu) * (i - mu);
        }

        return Math.sqrt(squares / (T - 1));
    }

    /**
     * Returns lower bound of the 95% confidence interval
     */
    public double confidenceLo()
    {
        return mean() - 1.96 * stddev() / Math.sqrt(T);
    }

    /**
     * Returns upper bound of the 95% confidence interval
     */
    public double confidenceHi()
    {
        return mean() + 1.96 * stddev() / Math.sqrt(T);
    }

    private void simulate(int trial)
    {
        Percolation p = new Percolation(N);
        int openSites = 0;

        while (!p.percolates())
        {
            int i = StdRandom.uniform(N) + 1;
            int j = StdRandom.uniform(N) + 1;

            if (!p.isOpen(i, j))
            {
                p.open(i, j);
                openSites++;
            }
        }

        xi[trial] = openSites / (N * N);
    }

    /**
     * Test client
     */
    public static void main(String[] args)
    {
        int N = Integer.parseInt(args[0]);
        int T = Integer.parseInt(args[1]);

        PercolationStats ps = new PercolationStats(N, T);
        StdOut.println("mean\t\t\t= " + ps.mean());
        StdOut.println("stddev\t\t\t= " + ps.stddev());
        StdOut.println("95% confidence interval = " + ps.confidenceLo() + ", " + ps.confidenceHi());
    }


}
