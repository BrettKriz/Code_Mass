Public Class Form3
    Public FromGame As Boolean
    Dim lol As Integer
    Private Sub Button1_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button1.Click
        'Back to menu
        Me.Close()

    End Sub

    Private Sub Form3_Disposed(ByVal sender As Object, ByVal e As System.EventArgs) Handles Me.Disposed
        'On Remove
        If FromGame = True Then
            Form1.Visible = True
        Else
            Form2.Visible = True
        End If
    End Sub

    Private Sub Button2_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button2.Click

    End Sub

    Private Sub Button2_MouseEnter(ByVal sender As Object, ByVal e As System.EventArgs) Handles Button2.MouseEnter
        'lol
        If lol = 0 Then
            Button2.Text = "QQ moar?"
        ElseIf lol = 1 Then
            Button2.Text = "U mad bro?"
        ElseIf lol = 2 Then
            Button2.Text = "Ya, you like what I did there?"
        ElseIf lol > 100 Then
            Button2.Text = "Dont you have something better to do Fox?"
        Else
            Button2.Text = "LOLOLOOLOLOL"
        End If

        LOLOL()
    End Sub
    Private Sub LOLOL()
        lol = lol + 1
        Label2.Text = lol
    End Sub

    Private Sub Button2_MouseLeave(ByVal sender As Object, ByVal e As System.EventArgs) Handles Button2.MouseLeave


        If lol > 2 Then
            Button2.Text = "Why do you keep mousing over? :D"
        Else
            Button2.Text = "I dont live under a rock -,-"
        End If
    End Sub
End Class