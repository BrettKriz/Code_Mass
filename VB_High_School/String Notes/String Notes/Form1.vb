Public Class Form1

    Private Sub Button3_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button3.Click
        'String notes

        'String literal: a string enclosed in quotes.
        'for example:
        MsgBox("Chemic")

        'String variable: a string stored in a variable
        Dim str As String
        str = "chemic"

        '4 STRING COMMANDS
        '*****************

        '1. length (the number of characters in a string)
        Dim x As Integer
        x = str.Length 'X now holds a 6
        MsgBox("length of str: " & x)

        '2. IndexOf (searches a string for a phrase)
        'returns the location of where the phrase
        'was found or -1 if not found
        Dim y As Integer
        y = str.IndexOf("Mi") 'could be a single letter
        MsgBox("location of mi: " & y)

        y = str.IndexOf("apple") 'not found
        MsgBox("location of apple: " & y) '-1

        'IndexOf will only find the first instance of the phrase
        Dim str2 As String
        str2 = "apple"
        y = str2.IndexOf("P") '1 since we stop after the 1st P

        '3. substring (pulls a string out of a string)
        Dim str3, str4 As String
        str3 = "I am a big yellow tennis ball"
        str4 = str3.Substring(11, 6) '11 = where to Start, 6 = HOW MANY CHARACTERS U WANT TO GRAB!!!
        MsgBox("a substring: " & str4) 'yellow

        '4. ToUpper and ToLower
        str4 = str4.ToUpper 'I need str4 = if I want it to change
        MsgBox("demo ToUpper" & str4)
        str = str.ToLower
        MsgBox("demo ToLower" & str)

    End Sub

    Private Sub Button1_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button1.Click

        Dim n As String
        n = TextBox1.Text

        'Find the location of space 1
        Dim space1 As Integer
        space1 = n.IndexOf(" ")

        'Get the first name
        Dim first As String
        first = n.Substring(0, space1)
        MsgBox(first)

        'get te 2nd space (we want the 2nd one not the 1st)
        Dim space2 As Integer
        space2 = n.IndexOf(" ", space1 + 1) 'optinal start spot

        'get the middle name
        Dim middle As String
        middle = n.Substring(space1 + 1, space2 - space1 - 1)
        MsgBox(middle)

        'get the last name
        Dim last As String
        last = n.Substring(space2 + 1)
        MsgBox(last)

    End Sub

    Private Sub Button2_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button2.Click
        Dim n, letter As String
        n = TextBox1.Text

        Dim count As Integer 'count the number of Ms

        'The for/next loop
        Dim x As Integer
        For x = 0 To n.Length - 1
            letter = n.Substring(x, 1)
            If letter = "m" Then
                count = count + 1
            End If
        Next

        MsgBox(count)
    End Sub
End Class
