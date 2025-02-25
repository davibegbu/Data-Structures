//David Ibegbu

import java.util.Random; 
import java.time.Duration;
import java.time.Instant;
import java.time.LocalTime;
import java.time.format.DateTimeFormatter;

final class SolverNQueen
{

   public static void main(String[] args) 
   {
      iteratvieRepair(5000);
   }

   private static int[] iteratvieRepair(int n) 
   {
      int boardDimension = n;
      Instant begin = Instant.now();
      int[] chessBoard = generateBoard(boardDimension);  
      int attackNums; 
      int[] newBoard;
      int newAttacknums;
      //This was for Data collection
      int swapCount = 0;
      boolean solutionFound = false; 

      if (n < 3)
      {
         return null;
      }
      
      System.out.println("Here is the board that is generated: \n");
      printBoard(chessBoard, boardDimension);
      
      attackNums = findAttacks(chessBoard);
      
      //This forces the program to keep looking for a solution until the number of attacks reported is less than one
      while (attackNums > 1)
      {
         for(int i = 0; i < boardDimension; i++)
         {
            for(int j = i+ 1; j < boardDimension; j++)
            {
               if(isAttacked(chessBoard,i,j))
               {
                  newBoard = swapQueens(chessBoard,i,j);
                  newAttacknums = findAttacks(newBoard);
                  swapCount++; 

                  if (newAttacknums < attackNums)
                  {                     
                     attackNums = newAttacknums;
                     chessBoard = newBoard; 
                     if (attackNums == 0)
                     {
                        solutionFound = true; 
                        System.out.println("\nSolution found. This Board has no attacks: \n");
                        printBoard(chessBoard, boardDimension);
                        break; 

                     }
                  }               
               }
            }  
            if (solutionFound) 
            {
               break;
            }
         }
         if (!solutionFound) 
         {
            chessBoard = generateBoard(boardDimension);
            // Update attacks
            attackNums = findAttacks(chessBoard);
         }
      }
      Instant finish = Instant.now();
      Duration duration = Duration.between(begin, finish);
      System.out.println("\nThere were " +  swapCount + " board resets.");
      System.out.println("\nTime taken (Minutes:Seconds:Milliseconds.Microseconds): " + LocalTime.ofNanoOfDay(duration.toNanos()).format(DateTimeFormatter.ofPattern("mm:ss:SSS.SSSSSS\n")));
      return chessBoard;
   }
   
   //This method will look at the board given and check for diagonal attacks
   private static int findAttacks(int[] N)
   {
      int attackSum= 0;
      //Diagonal from top left to bottom right
      int []diagCount1 = new int[(2*N.length) - 1];
      //Diagonal from top right to bottom left
      int []diagCount2 = new int[(2*N.length) - 1]; 
      
      //This is counting the number of attacks/queens in the Diagonal
      for (int i = 0; i < N.length; i++)
      {
         diagCount1[i + N[i]]++;
         diagCount2[i - N[i] + N.length - 1]++;
         if (diagCount1[i + N[i]] > 1)
         {
            attackSum += diagCount1[i + N[i] - 1];
         }
      }

      // This goes through the diagonal array if there is more than one queen present it is registered as an attack
      for( int i = 0; i < diagCount1.length; i++ )
      {
         if(diagCount1[i] > 1)
         {
            attackSum += diagCount1[i] - 1;
         }
         if(diagCount2[i] > 1)
         {
            attackSum += diagCount2[i] - 1;
         }
      }

      return attackSum;
   }
   
//Generates the baord
 private static int[] generateBoard(int n)
   {
      int[] board = new int[n];
      Random random = new Random();
      
      //Randomly places the queen on the board
      for(int i = 0; i < n; i++)
      {
         board[i] = i;
      }
      
      for (int i = n -1; i > 0; i--)
      {
         int j = random.nextInt(i + 1);
         int temp = board[i];
         board[i] = board[j];
         board[j] = temp; 
      }
      
      return board; 
   } 

   //This method will take the board and the two specified places on the board and will swap them and return a new board with the changes
   private static int[] swapQueens(int[] board, int i, int j)
   {
      int [] newBoard = board.clone();
      newBoard[i] = board[j];
      newBoard[j] = board[i];

      return newBoard;

   }
   
   //This is a method that will print out any board given to it
   private static void printBoard(int [] board, int n)
   {   
      for (int i = 0; i < board.length; i++)
      {
         System.out.print(board[i] + " ");
         if ((i + 1) % n == 0)
         {
             System.out.println();
         }
      }
   }
   //This Method will recieve the board and two integers which will represent the two postions on the board and see if they are attacking one another 
   private static boolean isAttacked(int [] board, int i, int j) 
   {
      if (board[i] == board[j])
      {
         return true; 
      }
      //Check to see if the queen at i is attacked by queen at j
      if (Math.abs(board[i] - board[j]) == Math.abs(i-j))
      {
         return true;
      } 
      // Check to see if either queen is attacked by another queen
      for (int k = 0; k < board.length; k++) 
      {
            
         if (k != i && k != j) 
         {
               if (board[i] == board[k]) 
               {
                  return true;
               }
               if (board[j] == board[k]) 
               {
                 return true;
               }
               if (Math.abs(board[i] - board[k]) == Math.abs(i - k)) 
               {
                 return true;
               }
               if (Math.abs(board[j] - board[k]) == Math.abs(j - k))
               {
                 return true;
               }
         }
      }

      return false;
   }

}