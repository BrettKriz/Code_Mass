package cs2321;

import java.io.*;
import java.util.Scanner;
import java.util.Iterator;
import net.datastructures.*;

/* CS2321 Project: The Labyrinth
 * 
 * 
 * Part A: Use the main method in this class for testing purposes.
 *         Do NOT change the setupLabyrinth function, except for
 *         uncommenting the graph implementation that you have chosen.
 *         
 * Part B: Implement the dfsPath, bfsPath, shortestPath, and
 *         totalPathDistance functions below.
 *         
 * Part C: Implement LabyrinthPanel and LabyrinthFrame
 */
public class Labyrinth
{
    public static final int WALL = 1;
    public static final String PARSE_CHARACTER = ",";

    private Graph<RoomCoordinate, Walkway> mGraph;
    private int mWidth = -1;
    private int mHeight = -1;

    public static void main( String[] aArguments )
    {
        Labyrinth lab = new Labyrinth( "SmallLabyrinth.txt" );

        
    }

    public Labyrinth( String aFileName )
    {
        mGraph = setupLabyrinth( aFileName );

        // TODO: Add other necessary code to constructor
    }

    /*
     * Width of the labyrinth (# of squares, not pixels)
     */
    public int getWidth()
    {
        return mWidth;
    }

    /*
     * Height of the labyrinth (# of squares, not pixels)
     */
    public int getHeight()
    {
        return mHeight;
    }

    public Graph<RoomCoordinate, Walkway> setupLabyrinth( String aFileName )
    {
        Scanner lFile = null;
        try
        {
            lFile = new Scanner( new File( aFileName ) );
            lFile.useDelimiter( ",\n" );
        }
        catch ( FileNotFoundException eException )
        {
            System.out.println( eException.getMessage() );
            eException.printStackTrace();
            System.exit( -1 );
        }

        /*
         * TODO: Project Part A: Pick your implementation and uncomment
         */
        //# Graph<RoomCoordinate, Walkway> lGraph = new EdgeListGraph<RoomCoordinate, Walkway>();
        Graph<RoomCoordinate, Walkway> lGraph = new AdjListGraph<RoomCoordinate, Walkway>();
        //# Graph<RoomCoordinate, Walkway> lGraph = new AdjMatrixGraph<RoomCoordinate, Walkway>();

        try
        {
            int lXSize = 0;
            int lYSize = 0;
            if ( lFile.hasNext() )
            {
                String[] lDimensions = lFile.nextLine().split( PARSE_CHARACTER );
                lXSize = Integer.parseInt( lDimensions[0] );
                lYSize = Integer.parseInt( lDimensions[1] );
            }

            mWidth = lXSize;
            mHeight = lYSize;

            /* Create all the room coordinates */
            Vertex<?>[][] lVertices = new Vertex<?>[lXSize][lYSize];
            for ( int lYIndex = 0; lYIndex < lYSize; lYIndex++ )
            {
                for ( int lXIndex = 0; lXIndex < lXSize; lXIndex++ )
                {
                    RoomCoordinate lNextRoomCoordinate = new RoomCoordinate(
                            lXIndex, lYIndex );
                    Vertex<RoomCoordinate> lNextRoom = lGraph
                            .insertVertex( lNextRoomCoordinate );
                    lVertices[lXIndex][lYIndex] = lNextRoom;
                }
            }

            for ( int lYIndex = 0; lYIndex < lYSize; lYIndex++ )
            {
                String[] lWalls = lFile.nextLine().split( PARSE_CHARACTER );
                for ( int lXIndex = 0; lXIndex < lXSize; lXIndex++ )
                {
                    if ( Integer.parseInt( lWalls[lXIndex] ) != WALL )
                    {
                        Vertex<RoomCoordinate> lVertex1 = ( Vertex<RoomCoordinate> )lVertices[lXIndex][lYIndex];
                        Vertex<RoomCoordinate> lVertex2 = ( Vertex<RoomCoordinate> )lVertices[lXIndex][lYIndex - 1];

                        Walkway lNewWalkway = new Walkway( lVertex1.element()
                                .toString() + lVertex2.element().toString(), 1 );
                        lGraph.insertEdge( lVertex1, lVertex2, lNewWalkway );
                    }
                }
            }

            for ( int lYIndex = 0; lYIndex < lYSize; lYIndex++ )
            {
                String[] lWalls = lFile.nextLine().split( PARSE_CHARACTER );
                for ( int lXIndex = 0; lXIndex < lXSize; lXIndex++ )
                {
                    if ( Integer.parseInt( lWalls[lXIndex] ) != WALL )
                    {
                        Vertex<RoomCoordinate> lVertex1 = ( Vertex<RoomCoordinate> )lVertices[lXIndex][lYIndex];
                        Vertex<RoomCoordinate> lVertex2 = ( Vertex<RoomCoordinate> )lVertices[lXIndex - 1][lYIndex];

                        Walkway lNewWalkway = new Walkway( lVertex1.element()
                                .toString() + lVertex2.element().toString(), 1 );
                        lGraph.insertEdge( lVertex1, lVertex2, lNewWalkway );
                    }
                }
            }
        }
        catch ( Exception eException )
        {
            System.out.println( eException.getMessage() );
            eException.printStackTrace();
            System.exit( -1 );
        }

        return lGraph;
    }
    
    /* START PROJECT PART B */

    /* Project Part B:
     * Complete the dfsPath function by implementing a Depth First Search algorithm
     * to find a path from start to end.
     * RETURN VALUES:
     *    + If there is NO path, do NOT return null.  Return an empty sequence.
     *    + If there is a path, return the sequence of edges traversed in order
     *      to get from the start to the finish locations.
     */
    public Sequence<Edge<Walkway>> dfsPath( RoomCoordinate start, RoomCoordinate end )
    {
        // #TODO: Complete and correct dfsPath()
        /* #TODO: TCJ / SCJ! */
        
        return null;
    }

    /* Project Part B:
     * Complete the bfsPath function by implementing a Breadth First Search algorithm
     * to find a path from start to end.
     * RETURN VALUES:
     *    + If there is NO path, do NOT return null.  Return an empty sequence.
     *    + If there is a path, return the sequence of edges traversed in order
     *      to get from the start to the finish locations.
     */
    public Sequence<Edge<Walkway>> bfsPath( RoomCoordinate start, RoomCoordinate end )
    {
        // #TODO: Complete and correct bfsPath()
        /* #TODO: TCJ / SCJ! */
        return null;
    }

    /* Project Part B:
     * Complete the shortestPath function by implementing Dijkstra's Algorithm
     * to find a path from start to end.
     * RETURN VALUES:
     *    + If there is NO path, do NOT return null.  Return an empty sequence.
     *    + If there is a path, return the sequence of edges traversed in order
     *      to get from the start to the finish locations.
     */
    public Sequence<Edge<Walkway>> shortestPath( RoomCoordinate start, RoomCoordinate end )
    {
        // #TODO: Complete and correct shortestPath()
        /* #TODO: TCJ / SCJ! */
        return null;
    }
    
    /* Project Part B:
     * Complete the totalPathDistance function, which calculates how far the given
     * path traverses.
     */
    public static double totalPathDistance( Sequence<Edge<Walkway>> path )
    {
        //# TODO: Complete totalPathDistance function
        return 0;
    }

    /* END PROJECT PART B */

}
