Public Class Form1
    'Public makes it visable on ALL FORMS
    'Dim the names and the character they want to use
    Public P1_Name, P1_STR, P2_Name, P2_STR As String
    Public p1_pic, P2_Pic As Image
    Public Use_Pics As Boolean
    'I assume global makes it visable throughout the PC
    Dim turn_pic As Image
    Dim Board(2, 2), Turn_STR As String
    Dim Button_Board(2, 2) As Button
    Dim Rand As New Random
    Dim Turn_Num, P1_vict, P2_vict As Integer
    Dim Turn As Boolean
    Private Sub Form1_Disposed(ByVal sender As Object, ByVal e As System.EventArgs) Handles Me.Disposed
        'what to do when the from1 is closed
        Form2.Close()
    End Sub
    Private Sub Form1_Load(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles MyBase.Load
        'Set Variables
        Bool2LablSTR()
        'NOTE: ITS NOT SWITCHING THE TURN BOOL!
        P1_vict = 0
        P2_vict = 0

        If Use_Pics = True Then

        End If

        Button_Board(0, 0) = Button1
        Button_Board(0, 1) = Button2
        Button_Board(0, 2) = Button3
        Button_Board(1, 0) = Button4
        Button_Board(1, 1) = Button5
        Button_Board(1, 2) = Button6
        Button_Board(2, 0) = Button7
        Button_Board(2, 1) = Button8
        Button_Board(2, 2) = Button9

        '...before i use them here
            Clear_Board()

    End Sub
    Private Sub Bool2LablSTR()
        'streamline this process
        If Turn = True Then
            'P1
            Label1.Text = P1_Name
        ElseIf Turn = False Then
            'P2
            Label1.Text = P2_Name
        End If

        If Use_Pics = False Then
            If Turn = True Then
                Turn_STR = P1_STR
            Else
                Turn_STR = P2_STR
            End If
        Else
            If Turn = True Then
                turn_pic = p1_pic
            Else
                turn_pic = P2_Pic
            End If
        End If
    End Sub
    Private Sub Clear_Board()
        'Set or Reset the board
        Dim Row, Col As Integer

        'Try to reset

        Bool2LablSTR()

            For Row = 0 To 2
                For Col = 0 To 2
                Board(Row, Col) = "Problem, String Value? <TrollFace" & Rand.Next(1, 8000) & ".JPG>"
                Button_Board(Row, Col).Enabled = True
                Button_Board(Row, Col).Text = " "
                If Use_Pics = True Then
                    Button_Board(Row, Col).Image = New Bitmap("U:\pictures\test.jpg")
                End If
                Next
        Next


        Turn_Num = 0

    End Sub

    Private Sub Win_Letter(ByVal Direction As String)
        'Just CAUSE
        If Turn_STR = P1_STR Then
            MsgBox("Player " & P1_Name & " Won " & Direction & "!")
            P1_vict = P1_vict + 1
        ElseIf Turn_STR = P2_STR Then
            MsgBox("Player " & P2_Name & " Won " & Direction & "!")
            P2_vict = P2_vict + 1
        End If

        'Need to debug
        Clear_Board()
    End Sub
    Private Sub Win_Check(ByVal Button_Number As Button)

        Button_Number.Enabled = False
        'Check arrays for a win

        If Board(0, 0) = Turn_STR And Board(1, 0) = Turn_STR And Board(2, 0) = Turn_STR Then
            'Check Row 1 for win
            Win_Letter("Horizontaly in the Top Row")

        ElseIf Board(0, 1) = Turn_STR And Board(1, 1) = Turn_STR And Board(2, 1) = Turn_STR Then
            'Check Row 2
            Win_Letter("Horizontaly in the Middle Row")

        ElseIf Board(0, 2) = Turn_STR And Board(1, 2) = Turn_STR And Board(2, 2) = Turn_STR Then
            'Check Row 3
            Win_Letter("Horizontaly in the Low Row")



        ElseIf Board(0, 0) = Turn_STR And Board(0, 1) = Turn_STR And Board(0, 2) = Turn_STR Then
            'Check Col 1
            Win_Letter("Verticaly in the 1st Coloum")

        ElseIf Board(1, 0) = Turn_STR And Board(1, 1) = Turn_STR And Board(1, 2) = Turn_STR Then
            'Check Col 2
            Win_Letter("Verticaly in the 2nd Coloum")

        ElseIf Board(2, 0) = Turn_STR And Board(2, 1) = Turn_STR And Board(2, 2) = Turn_STR Then
            'Check Col 3
            Win_Letter("Verticaly in the 3rd Coloum")


        ElseIf Board(0, 0) = Turn_STR And Board(1, 1) = Turn_STR And Board(2, 2) = Turn_STR Then
            'Check RIGHT Diagonal
            Win_Letter("Diagonaly from the right")

        ElseIf Board(0, 2) = Turn_STR And Board(1, 1) = Turn_STR And Board(2, 0) = Turn_STR Then
            'Check LEFT Diagonal
            Win_Letter("Diagonaly from the left")

        ElseIf Turn_Num = 8 Then
            'CATS GAME
            MsgBox("Cats Game")
            Clear_Board()
        End If

    End Sub

    Private Sub AI()
        'Run a bit of logic.
        Dim Random_Col, Random_Row, Row, Col As Integer


        If RadioButton2.Checked = True Then
            'Decide by random
            Random_Col = Rand.Next(0, 3)
            Random_Row = Rand.Next(0, 3)

            'Check it
            Do While Not Button_Board(Random_Row, Random_Col).Enabled = True
                'Its taken?
                'try another button
                Random_Col = Rand.Next(0, 3)
                Random_Row = Rand.Next(0, 3)
            Loop

            'Its finaly Returned true
            If Use_Pics = False Then
                Button_Board(Random_Row, Random_Col).Text = Turn_STR
            Else
                Button_Board(Random_Row, Random_Col).Image = turn_pic
            End If
            Board(Random_Row, Random_Col) = Turn_STR
            'Its having some issue with this lineS
            Win_Check(Button_Board(Random_Row, Random_Col))
        Else
            'An Error
            MsgBox("AI is off turn, or cant meet paramiters")
        End If

    End Sub

    Private Sub Button_Change(ByVal Button_Number As Button, ByVal Row As Integer, ByVal Col As Integer)
        'Change text
        'Define the str and pics
        Bool2LablSTR()
        'Change em
        If Use_Pics = False Then
            Button_Number.Text = Turn_STR
        Else
            Button_Number.Image = turn_pic
        End If

        If Turn = True Then
            Board(Row, Col) = Turn_STR
            Win_Check(Button_Number)

            '*********Run AIs turn*********
            If RadioButton1.Checked = False Then
                'Call AI
                AI()
                'Turn = True

            End If

        Else    '*********Player 2*********
            'Make sure its PVP
            Button_Number.Text = Turn_STR
            Board(Row, Col) = Turn_STR
            Win_Check(Button_Number)

            'Turn = True
            
        End If

        If Turn = False Then
            Turn = True
        Else
            Turn = False
        End If

            Turn_Num = Turn_Num + 1


    End Sub

    Private Sub Button11_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button11.Click
        Me.Close()
        Form2.Close()
    End Sub

    Private Sub Button1_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button1.Click
        Button_Change(Button1, 0, 0)
    End Sub

    Private Sub Button2_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button2.Click
        Button_Change(Button2, 1, 0)
    End Sub

    Private Sub Button3_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button3.Click
        Button_Change(Button3, 2, 0)
    End Sub

    Private Sub Button4_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button4.Click
        Button_Change(Button4, 0, 1)
    End Sub

    Private Sub Button5_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button5.Click
        Button_Change(Button5, 1, 1)
    End Sub

    Private Sub Button6_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button6.Click
        Button_Change(Button6, 2, 1)
    End Sub

    Private Sub Button7_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button7.Click
        Button_Change(Button7, 0, 2)
    End Sub

    Private Sub Button8_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button8.Click
        Button_Change(Button8, 1, 2)
    End Sub

    Private Sub Button9_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button9.Click
        Button_Change(Button9, 2, 2)
    End Sub

    Private Sub Button10_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button10.Click
        'NEW GAME
        Clear_Board()

    End Sub

    Private Sub Button11_MouseEnter(ByVal sender As Object, ByVal e As System.EventArgs) Handles Button11.MouseEnter
        Button11.Text = "Quit?"
    End Sub

    Private Sub Button11_MouseLeave(ByVal sender As Object, ByVal e As System.EventArgs) Handles Button11.MouseLeave
        Button11.Text = "Quit"
    End Sub

    Private Sub SaveToolStripMenuItem_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles SaveToolStripMenuItem.Click
        'Open file for output
        'it's created automatially when you open output.
        Dim row, col As Integer
        FileOpen(1, "game.txt", OpenMode.Output)

        'Output the names, turn, scores
        'note that you may have diffrent names for your vars
        'and you may even have more vars depending on how you wrote it
        PrintLine(1, P1_Name)  'name
        PrintLine(1, P2_Name)  'name
        PrintLine(1, P1_vict) 'score1
        PrintLine(1, P2_vict)   'score2
        PrintLine(1, Turn)  'Turn
        PrintLine(1, Turn_Num)

        PrintLine(1, Use_Pics)  'Picture game?

        If Use_Pics = False Then
            PrintLine(1, P1_STR)    'p1 char
            PrintLine(1, P2_STR)    'p2 char
        Else
            PrintLine(1, P1_Pic)      'p1 Image
            PrintLine(1, P2_Pic)      'p2 Image
        End If

        For row = 0 To 2
            For col = 0 To 2
                PrintLine(1, Board(row, col))
            Next
        Next

        'output the x/o array
        For row = 0 To 2
            For col = 0 To 2
                    PrintLine(1, Button_Board(row, col).Text)
            Next
        Next

        FileClose(1)
    End Sub

    Private Sub LoadToolStripMenuItem_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles LoadToolStripMenuItem.Click
        'Load
        Dim row, col As Integer

        FileOpen(1, "game.txt", OpenMode.Input)
        'Read in the info
        Input(1, P1_Name)
        Input(1, P2_Name)
        Input(1, P1_vict)
        Input(1, P2_vict)
        Input(1, Turn)
        Input(1, Turn_Num)
        'Use picutres setting
        Input(1, Use_Pics)

        If Use_Pics = False Then
            Input(1, P1_STR)    'p1 char
            Input(1, P2_STR)    'p2 char
        Else
            Input(1, p1_pic)      'p1 Image
            Input(1, P2_Pic)      'p2 Image 
        End If

        'Input the acutal board
        For row = 0 To 2
            For col = 0 To 2
                Input(1, Board(row, col))
            Next
        Next

        'input the x/o array
        For row = 0 To 2
            For col = 0 To 2

                Input(1, Button_Board(row, col).Text)
                If Use_Pics = False Then
                    If Board(row, col) = P1_STR Or Board(row, col) = P2_STR Then
                        'ITS USED
                        Button_Board(row, col).Enabled = False
                    End If
                Else
                    If Board(row, col) = P1_STR Then
                        Button_Board(row, col).Image = p1_pic
                    ElseIf Board(row, col) = P2_STR Then
                        Button_Board(row, col).Image = P2_Pic
                    End If
                End If
            Next
        Next


        FileClose(1)
    End Sub

    Private Sub QuitToolStripMenuItem_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles QuitToolStripMenuItem.Click
        Me.Close()
        Form2.Close()
    End Sub

    Private Sub NewGameToolStripMenuItem_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles NewGameToolStripMenuItem.Click
        Clear_Board()
    End Sub

    Private Sub HowToPlayToolStripMenuItem_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles HowToPlayToolStripMenuItem.Click
        'goto how to play
        Form3.FromGame = True
        Form3.Visible = True
        Me.Visible = False
    End Sub
End Class
