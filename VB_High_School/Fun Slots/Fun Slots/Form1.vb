Public Class Form1
    Dim Bet_Amount As Integer
    Dim Tokens As Integer
    Private Sub Button1_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button1.Click
        'Set up number randomizer
        Dim Rand As New Random
        'Set up 3 numbers
        Dim num1, num2, num3 As Integer

        'Check if any radio buttons are checked
        If RadioButton4.Checked = True Then
            Bet_Amount = TextBox1.Text
        ElseIf RadioButton1.Checked = True Then
            Bet_Amount = 5
        ElseIf RadioButton2.Checked = True Then
            Bet_Amount = 10
        ElseIf RadioButton3.Checked = True Then
            Bet_Amount = Tokens
        End If

        If Bet_Amount > 0 And Tokens > 0 Then 'Make sure they have tokens and a bet
            num1 = Rand.Next(1, 8)
            num2 = Rand.Next(1, 8)
            num3 = Rand.Next(1, 8)
        End If


        'Display a picute based on the number of the card
        PictureBox1.Image = New Bitmap("u:\Pictures\slotimage_" & num1 & ".png")
        PictureBox2.Image = New Bitmap("u:\Pictures\slotimage_" & num2 & ".png")
        PictureBox3.Image = New Bitmap("u:\Pictures\slotimage_" & num3 & ".png")

        'Compair numbers to assign score
        If num1 = num2 And num1 = num3 Then
            If num1 = 7 And num2 = 7 And num3 = 7 Then
                'Super jack pot
                Tokens = Bet_Amount * 10
                MsgBox(" ~ Jack Pot ~ ")
            Else
                'Jack Pot
                Tokens = Bet_Amount * 5
                MsgBox("Jack Pot")
            End If
        ElseIf num1 = num2 Or num1 = num2 Or num2 = num3 Then
            'Small winnings
            Tokens = Tokens + Bet_Amount
        ElseIf num1 <> num2 And num1 <> num3 Then
            'Subtract Bet
            Tokens = Tokens - Bet_Amount

            'Show how many tokens we have now
            Label4.Text = Tokens
        ElseIf Tokens = 0 Then
            'No Tokens?
            MsgBox("No more tokens!")
            'Reset visuals and tokens
            Tokens = 100
            Label4.Text = Tokens
            PictureBox1.Image = New Bitmap("u:\Pictures\slotimage_0.png")
            PictureBox2.Image = New Bitmap("u:\Pictures\slotimage_0.png")
            PictureBox3.Image = New Bitmap("u:\Pictures\slotimage_0.png")
        Else
            'No bet?
            MsgBox("Check a bet amout!")
        End If
    End Sub

    Private Sub Form1_Load(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles MyBase.Load
        Tokens = 100
        Label4.Text = Tokens
        PictureBox1.Image = New Bitmap("u:\Pictures\slotimage_0.png")
        PictureBox2.Image = New Bitmap("u:\Pictures\slotimage_0.png")
        PictureBox3.Image = New Bitmap("u:\Pictures\slotimage_0.png")
    End Sub
End Class
