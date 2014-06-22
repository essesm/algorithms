/****************************************************************************
 * Compilation: javac Percolation.java
 * Execution: None
 * Dependencies: WeightedQuickUnionUF.java
 *
 * Percolation
 *
 ***************************************************************************/

/**
 * The <tt>Percolation</tt> class solves the percolation problem. It uses the
 * WeightedQuickUnionUF data structure.
 *
 * @author Michael Esses
 */
public class Percolation
{
    private int N;
    private boolean[] sites;
    private WeightedQuickUnionUF uf1;
    private WeightedQuickUnionUF uf2;
    private boolean percolates;

    /**
     * Initializes an empty N-by-N grid, with all sites blocked
     * @throws java.lang.IndexOutOfBounds if N < 0
     * @param N the dimension of the N-by-N grid
     */
    public Percolation(int N)
    {
        if (N <= 0) throw new IllegalArgumentException("Dimension out of bounds");
        this.N = N;
        sites = new boolean[N * N + 2];
        uf1 = new WeightedQuickUnionUF(N * N + 2);
        uf2 = new WeightedQuickUnionUF(N * N + 2);

        for (int i = 1; i <= N; i++)
        {
            uf1.union(0, i);
            uf2.union(N * N + 1, N * N - i + 1);
        }
    }

    /**
     * Opens the site if it is not already
     * @param i the row of the N-by-N grid
     * @param j the column of the N-by-N grid
     */
    public void open(int i, int j)
    {
        sites[getOffset(i, j)] = true;

        if (i - 1 > 0 && sites[getOffset(i - 1, j)])
        {
            uf1.union(getOffset(i, j), getOffset(i - 1, j));
            uf2.union(getOffset(i, j), getOffset(i - 1, j));
        }

        if (j - 1 > 0 && sites[getOffset(i, j - 1)])
        {
            uf1.union(getOffset(i, j), getOffset(i, j - 1));
            uf2.union(getOffset(i, j), getOffset(i, j - 1));
        }

        if (j + 1 <= N && sites[getOffset(i, j + 1)])
        {
            uf1.union(getOffset(i, j), getOffset(i, j + 1));
            uf2.union(getOffset(i, j), getOffset(i, j + 1));
        }

        if (i + 1 <= N && sites[getOffset(i + 1, j)])
        {
            uf1.union(getOffset(i, j), getOffset(i + 1, j));
            uf2.union(getOffset(i, j), getOffset(i + 1, j));
        }

        if (uf1.connected(0, getOffset(i, j)) && uf2.connected(N * N + 1, getOffset(i, j)))
        {
            percolates = true;
        }
    }

    /**
     * Is the site open?
     * @param i the row of the N-by-N grid
     * @param j the column of the N-by-N grid
     */
    public boolean isOpen(int i, int j)
    {
        return sites[getOffset(i, j)];
    }

    /**
     * Is the site full?
     * @param i the row of the N-by-N grid
     * @param j the column of the N-by-N grid
     */
    public boolean isFull(int i, int j)
    {
        return uf1.connected(0, getOffset(i, j)) && isOpen(i, j);
    }

    /**
     * Does the system percolate?
     */
    public boolean percolates()
    {
        return percolates;
    }

    /**
     * Gets the offset of the coordinates
     * @throws java.lang.IndexOutOfBounds if i <= 0, i > N, j <= 0, or j > N
     * @param i the row of the N-by-N grid
     * @param j the column of the N-by-N grid
     */
    private int getOffset(int i, int j)
    {
        if (i <= 0 || i > N) throw new IndexOutOfBoundsException("row index i out of bounds");
        if (j <= 0 || j > N) throw new IndexOutOfBoundsException("column index j out of bounds");

        return (i - 1) * N + j;
    }

    public static void main(String[] args)
    {
        Percolation p = new Percolation(3);
        assert !p.percolates();
        p.open(1, 1);
        assert p.isOpen(1, 1);
        assert p.isFull(1, 1);
        assert !p.percolates();
        p.open(2, 2);
        assert p.isOpen(2, 2);
        assert !p.isFull(2, 2);
        assert !p.percolates();
        p.open(2, 1);
        assert p.isOpen(2, 1);
        assert p.isFull(2, 2);
        assert p.isFull(2, 1);
        p.open(3, 3);
        assert p.isOpen(3, 3);
        assert !p.isFull(3, 3);
        p.open(3, 1);
        assert p.isOpen(3, 1);
        assert p.isFull(3, 1);
        assert !p.isFull(3, 3);
        assert p.percolates();
    }
}
