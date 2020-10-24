Public Class Form1

    Private Sub Button1_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button1.Click
        'Create vars
        Dim input_cents, Quarters, Dimes, Nickels, Pennies As Integer

        input_cents = TextBox1.Text

        Quarters = input_cents \ 25

        Dimes = input_cents \ 10

        Nickels = input_cents \ 5

        Pennies = input_cents Mod 100

        'Display values
        Label1.Text = Quarters
        Label2.Text = Dimes
        Label3.Text = Nickels
        Label4.Text = Pennies

    End Sub

    Private Sub Button2_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button2.Click
        Me.Close()
    End Sub
End Class
