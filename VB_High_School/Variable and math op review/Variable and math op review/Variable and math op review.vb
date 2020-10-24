Public Class Form1

    Private Sub Button1_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button1.Click
        'Age value
        Dim HR_age As Double
        'HR_age = input
        HR_age = TextBox1.Text
        'Heart rate Variable
        Dim h_rate As Double
        'Use formula, *85 dosent work out*
        h_rate = 0.95 * (200 - HR_age)
        'Display
        Label10.Text = h_rate

    End Sub

    Private Sub Button2_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button2.Click
        'Answer value
        Dim t_answer As Double
        'Area value, for pre calculation formula
        Dim Area As Double

        Dim side1 As Double
        Dim side2 As Double
        Dim side3 As Double

        side1 = TextBox2.Text
        side2 = TextBox3.Text
        side3 = TextBox3.Text

        'Calculate the Area value
        Area = (side1 + side2 + side3) / 2.0
        'Calculate the Answer value
        t_answer = Math.Sqrt(Area * (Area - side1) * (Area - side2) * (Area - side3))
        'For some reason, the anser is a bit off
        'Display T answer
        Label11.Text = Format(t_answer, "###.#")

    End Sub

    Private Sub Button3_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button3.Click
        'Celcius Value
        Dim celc As Double
        'Calculate Celc value
        celc = (5 / 9) * (TextBox5.Text - 32)
        'Display Celc
        Label13.Text = celc

    End Sub

    Private Sub Button4_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button4.Click
        'Set up q answer
        Dim q_answer As Double
        'Calculate q answer
        q_answer = ((-1 * TextBox7.Text) + Math.Sqrt((TextBox7.Text) ^ 2 - (4 * TextBox6.Text * TextBox8.Text))) / (TextBox6.Text * 2)
        'Display q answer
        Label16.Text = q_answer

    End Sub
End Class
