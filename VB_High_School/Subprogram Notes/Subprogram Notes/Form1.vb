Public Class Form1
    'SUBPROGRAM - WHAT IS IT?
    '************************
    'Subprograms are mini programs indisde of
    'programs
    'Every button has its own sub for example

    'SUBPROGRAMS - Why?
    '******************

    '1. Manage complexity by breakiong up a comples task into subtasks
    '2. Reuse code
    '3. Easier debugging
    '4. Easier to read and understand
    '5. Standard SW engineering practice since 1970s

    'Goal: Identify "tasks" in your program
    'that are repeated and deligate them into subs

    Private Sub Button1_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button1.Click
        'Basic subprogram call
        mysub()


    End Sub

    'basic subprogram
    Private Sub mysub()
        'subprogram code
        MsgBox("This is a subprogram")
    End Sub
    'subprogram with parameters
    Private Sub mysub2(ByVal x As Integer, ByVal y As String)
        'task to preform:
        MsgBox("you sent: " & x & " " & y)
        'NORMALLY WE SHOULD USE X AND Y TO PREFORM SOME TASK
    End Sub

    Private Sub Button2_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button2.Click
        'call mysub 2 and sent it a value
        mysub2(5, "Hi")
        'or
        Dim y As Integer
        Dim s As String
        y = InputBox("enter a number")
        s = InputBox("enter a word")
        mysub2(y, s)

    End Sub

    Private Function demofunc(ByVal z As String)
        Dim str2 As String
        str2 = "Hello" & z
        Return str2 'sends the value of str2 back to caller
    End Function

    Private Sub Button3_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button3.Click
        Dim str As String
        str = demofunc("Chemic")
        MsgBox(str)
    End Sub

End Class
