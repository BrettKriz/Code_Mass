Public Class Form2

    Private Sub Button1_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button1.Click
        'Change form
        'set p1 name & char
        Form1.P1_Name = TextBox1.Text
        Form1.P1_STR = TextBox3.Text.ToUpper
        'and p2
        Form1.P2_Name = TextBox2.Text
        Form1.P2_STR = TextBox4.Text.ToUpper

        If CheckBox1.Checked = True Then
            Form1.p1_pic = New Bitmap(TextBox5.Text)
            Form1.P2_Pic = New Bitmap(TextBox6.Text)
        End If



        '
        'make form1 visable
        Form1.Visible = True

        Form1.Use_Pics = CheckBox1.CheckState
        'make this form invisable
        Me.Visible = False
    End Sub

    Private Sub Button2_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button2.Click
        'Change to help
        Form3.FromGame = False
        Form3.Visible = True
        Me.Visible = False
    End Sub

    Private Sub TextBox5_MouseClick(ByVal sender As Object, ByVal e As System.Windows.Forms.MouseEventArgs) Handles TextBox5.MouseClick
        'Check
        CheckBox1.Checked = True
    End Sub
    Private Sub TextBox6_MouseClick(ByVal sender As Object, ByVal e As System.Windows.Forms.MouseEventArgs) Handles TextBox6.MouseClick
        'check
        CheckBox1.Checked = True
    End Sub
    Private Sub TextBox3_MouseClick(ByVal sender As Object, ByVal e As System.Windows.Forms.MouseEventArgs) Handles TextBox3.MouseClick
        'uncheck
        CheckBox1.Checked = False
    End Sub
    Private Sub TextBox4_MouseClick(ByVal sender As Object, ByVal e As System.Windows.Forms.MouseEventArgs) Handles TextBox4.MouseClick
        'uncheck
        CheckBox1.Checked = False
    End Sub
End Class