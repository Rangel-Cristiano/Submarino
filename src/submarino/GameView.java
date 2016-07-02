package submarino;

import java.awt.BorderLayout;
import java.awt.Color;
import java.awt.GridLayout;
import java.util.Random;
import javax.swing.ImageIcon;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.JToolBar;
import javax.swing.border.EmptyBorder;

public final class GameView {private final JPanel mPanel = new JPanel(new BorderLayout(3, 3));
    private JLabel[][] mBoardLabels = new JLabel[SIZE][SIZE];
    private JFrame mFrame;
    private ImageIcon mBoatIcon, mGarbageIcon;
    private int mLine = 0, mColumn = 0;
    private static int SIZE = 30;
    public native String getChar();
    private int mLixos = 1;
    private static String UP = "[A", DOWN = "[B", RIGHT = "[C", LEFT = "[D";

    public GameView() {
        initializeBoard();

        mFrame = new JFrame("Submarino");
        mFrame.add(mPanel);
        mFrame.setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);
        mFrame.pack();
        mFrame.setVisible(true);

        receiveMoves();
    }

    private void initializeBoard() {
        final JPanel boardPanel;
        JToolBar tools = new JToolBar();      

        mPanel.setBorder(new EmptyBorder(5, 5, 5, 5));
        tools.setFloatable(false);
        mPanel.add(tools, BorderLayout.PAGE_START);
               
        boardPanel = new JPanel(new GridLayout(0, SIZE - 1));
        mPanel.add(boardPanel);
        
        for (Integer line = 0; line < SIZE - 1; line++) {
            for (Integer column = 0; column < SIZE  - 1; column++) {
                JLabel label = new JLabel();
                label.setOpaque(true);
                label.setBackground(Color.BLUE);
                
                mBoardLabels[line][column] = label;               
                
                boardPanel.add(mBoardLabels[line][column]);              
            }
        }
        
       mBoatIcon = new javax.swing.ImageIcon(getClass().getResource("/submarino/boat.png"));
       mGarbageIcon = new javax.swing.ImageIcon(getClass().getResource("/submarino/trash.png"));
        
        mBoardLabels[0][0].setIcon(mBoatIcon);
        
        Random random = new Random();      
        for (int i = 0; i < 15; i++) {  
          int randLine = 0, randColumn = 0;
          while (randLine == 0 && randColumn == 0){
               randLine = random.nextInt(SIZE);
               randColumn = random.nextInt(SIZE);               
	 }
        
          if (mBoardLabels[randLine][randColumn] != null)  mBoardLabels[randLine][randColumn].setIcon(mGarbageIcon);
        }
    }
    
    public void receiveMoves() {         
            while (mLixos > 0) {
                try {
                    final String result = getChar().trim();
                    
                    if (result.length() > 0) {
                        System.out.println(result);
                        updateView(result);
                    }
                    Thread.sleep(300);
                } catch (InterruptedException ex) {
                   throw new RuntimeException(ex);
                }
            }
     }
    
    public void updateView(final String move) {
        if(move.equals(UP) && mLine > 0) {
            mBoardLabels[mLine][mColumn].setIcon(null);
            mBoardLabels[--mLine][mColumn].setIcon(mBoatIcon);
        } else if(move.equals(DOWN) && (mLine + 1) < SIZE) {
            mBoardLabels[mLine][mColumn].setIcon(null);
            mBoardLabels[++mLine][mColumn].setIcon(mBoatIcon);
        } else if(move.equals(LEFT) && mColumn > 0) {
            mBoardLabels[mLine][mColumn].setIcon(null);
            mBoardLabels[mLine][--mColumn].setIcon(mBoatIcon);
        } else if(move.equals(RIGHT) && (mColumn + 1) < SIZE) {
            mBoardLabels[mLine][mColumn].setIcon(null);
            mBoardLabels[mLine][++mColumn].setIcon(mBoatIcon);
        }
    }
}
