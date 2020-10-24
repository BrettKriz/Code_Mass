Public Class Form1

    Private Sub Button1_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button1.Click
        'The = sign ASSSIGNS A VALUE to a property

        'Change the TXT color
        Label1.ForeColor = Color.Blue

        'Change the backbground color
        Label1.BackColor = Color.ForestGreen

    End Sub

    Private Sub Button2_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button2.Click
        'Change the label text
        Label1.Text = "Chemic Pride"

        'Notes:
        ' " " go around the value
        ' "Chemic Pride" = Mylabel.text <- ERROR
        ' Dont revese the order, dur
        'What I want to change on LEFT
        'What I want to chamge it goes on RIGHT
    End Sub

    Private Sub Button3_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button3.Click
        'Change Font
        'When I want to chamge the font, I must create a new one

        'Specify type face, size, and style
        Label1.Font = New Font("Arial", 16, FontStyle.Underline)

    End Sub

    Private Sub Button4_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button4.Click
        'Change the font, but leave the size alone
        Label1.Font = New Font("Arial", Label1.Font.Size, FontStyle.Bold)
        'Let the font define itself     ^^^^^^^^^^^^^^^^
    End Sub

    Private Sub Button5_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button5.Click
        ' End program
        Me.Close()
    End Sub
End Class
