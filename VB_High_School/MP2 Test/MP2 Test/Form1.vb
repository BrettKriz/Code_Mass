Public Class Form1

    Dim Rand As New Random

    Private Sub Button1_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button1.Click
        'Create Vars
        Dim The_Array(9), Largest, Sec_Largest, lowest As Integer

        For x = 0 To 9
            'assign values
            The_Array(x) = Rand.Next(1, 101)
        Next

        'Lowest
        For x = 0 To 9
            'Check for each 3
            If x = 0 Then
                'Clearly the first
                lowest = The_Array(x)
            ElseIf x > 0 And The_Array(x) < lowest Then
                lowest = The_Array(x)
            End If
            'Highests
            If The_Array(x) > Largest Then
                Largest = The_Array(x)
            End If
            '2nd highest
            If The_Array(x) < Largest And The_Array(x) > Sec_Largest Then
                Sec_Largest = The_Array(x)
            End If
        Next

        'output
        MsgBox("Lowest: " & lowest & " 2nd Highest: " & Sec_Largest & " Highest: " & Largest)
    End Sub

    Private Sub Button2_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button2.Click
        Dim state(50), useless As String
        Dim x As Integer
        FileOpen(1, "U:\programing_info\states.txt", OpenMode.Input)

        ListView1.View = View.Details

        Do While Not EOF(1)
            Input(1, state(x))
            Input(1, useless)

            If state(x).Length = 6 Then
                Dim row As New ListViewItem(state(x))
                ListView1.Items.Add(row)
            End If
            x = x + 1

        Loop
        FileClose(1)
    End Sub

    Private Sub Button3_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button3.Click
        'Create Vars
        Dim Zeros, Ones, Flip As Integer

        For x = 1 To 1000
            'Flip it.
            Flip = Rand.Next(0, 2)

            If Flip = 0 Then
                Zeros = Zeros + 1
            ElseIf Flip = 1 Then
                Ones = Ones + 1
            Else
                MsgBox("Count went to high!")
            End If

        Next

        MsgBox("Heads: " & Zeros & " Tails: " & Ones)
    End Sub

    Private Sub Button4_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button4.Click
        Magic_MSGBOX(711)
    End Sub

    Private Sub Button5_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button5.Click
        Magic_MSGBOX(10)
    End Sub

    Private Sub Button6_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button6.Click
        Magic_MSGBOX(101)
    End Sub

    Private Sub Magic_MSGBOX(ByVal Number As Integer)
        'Create 4msgboxs
        MsgBox("Todays number is " & Number)
        MsgBox("You should celebrate number " & Number & " day by purchasing " & Number & " cakes! (Why??)")
        MsgBox("Cakes are always a good choice!")
        MsgBox("Unless you have high cholesterol... then you should try " & Number & " apples")

    End Sub

    Private Sub Button7_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button7.Click
        Dim n, First, Last, Password As String
        Dim space1, space2, x, y, z As Integer

        Name = InputBox("Whats your name? (Last name must be >= 3)")

        'Fox your note variable names are so usefull
        space1 = Name.IndexOf(" ")
        First = Name.Substring(0, 1)
        space2 = Name.IndexOf(" ", space1 + 1)
        Last = Name.Substring(space2 + 1, 3)

        x = Rand.Next(1, 101)
        y = Rand.Next(1, 101)
        z = Rand.Next(1, 101)

        'Generate Password
        Password = First.ToLower & Last.ToLower & x & y & z
        MsgBox("Super secret password is " & Password)

    End Sub
End Class
