Public Class Form1
    Dim rand As New Random
    Dim Sorted As Boolean
    Dim State(49), Capital(49), User_Input, STR_out As String
    Private Sub Form1_Load(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles MyBase.Load
        Load_file()

    End Sub
    Private Sub Load_file()
        'Load states
        Dim file_path As String
        'lol fox
        'U:\programing_info\states.txt

        file_path = InputBox("Input the file directory! The WHOLE directory! IE U:\States.txt")
        FileOpen(1, file_path, OpenMode.Input)

        ListView1.View = View.Details
        Dim x As Integer

        Do While Not EOF(1)
            Input(1, State(x))
            Input(1, Capital(x))
            'Note to self, when alphabetizing, make capital organize by state too
            'listview1.clear would remove all colums, so were not going to show these in the begining
            'Dim row As New ListViewItem(State(x))
            'row.SubItems.Add(Capital(x))

            'ListView1.Items.Add(row)
            x = x + 1
        Loop
        FileClose(1)

    End Sub

    Private Sub Button5_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button5.Click
        'Alphabetize it, eh
        Organize_Array()
    End Sub

    Private Sub Button1_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button1.Click
        'Find Capital
        FindInArrays(False)

    End Sub

    Private Sub FindInArrays(ByVal Find_State As Boolean)
        Dim find_input As String
        Dim Search_resulted As Boolean
        find_input = TextBox1.Text
        Search_resulted = False

        'Loop it around
        For x = 0 To 49
            'Search for that string eh,
            If Find_State = True Then
                'Find your state
                If find_input.ToLower = Capital(x).ToLower Then
                    'Got it!
                    MsgBox("The state is " & State(x))
                    Search_resulted = True
                    x = 49
                End If
            Else
                'Your finding a capital, eh
                If find_input.ToLower = State(x).ToLower Then
                    MsgBox("The capital is " & Capital(x))
                    Search_resulted = True
                End If

            End If
        Next
        If Search_resulted = False Then
            'Couldnt find it after search
            MsgBox("Could not find '" & find_input & "'! Check the spelling")
        End If
        TextBox1.Clear()

    End Sub

    Private Sub Button3_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button3.Click
        'Give a random state
        Rand_Question(True)
    End Sub

    Private Sub Button4_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button4.Click
        'Give a random capital
        Rand_Question(False)
    End Sub
    Private Function Unique_Rand_Num(ByVal Range_min As Integer, ByVal Range_Max As Integer)
        'Create a random number
        Dim Generated_Num, Taken(49), upto_taken As Integer
        upto_taken = 0

        Generated_Num = rand.Next(Range_min, Range_Max)
        'Make sure upto taken dosent go to far
        If upto_taken > 49 Then
            upto_taken = 49
        End If

        'Okay we got a number, buuut is it taken?
        'Run a loop to check if that number has been used
        For x = 0 To upto_taken
            If Generated_Num = Taken(x) Then
                'Number is taken
                'Regenerate it, reset loops
                Generated_Num = rand.Next(Range_min, Range_Max)
                x = 0
            End If
            'It cant be done, if it keeps failing...
            'Sooo its all good bro
        Next
        Taken(upto_taken + 1) = Generated_Num

        Return Generated_Num 
    End Function

    'Generates the random questions for the quiz feature
    Private Sub Rand_Question(ByVal Find_State As Boolean)

        Dim Y, Ask_Howmany, Correct, x_end As Integer
        Dim Input_STR As String
        Ask_Howmany = InputBox("How many questions to be asked? (You can type 'quit' at anytime to bail out)")

        If Ask_Howmany > 50 Then
            'Theres only 50 states...
            Ask_Howmany = 50
        End If
        'Hide the listview, lol
        ListView1.Hide()

        If Find_State = True Then
            For x = 1 To Ask_Howmany
                'Define values
                Y = rand.Next(0, 49)
                Input_STR = InputBox(State(Y) & " has a capital of ... (type 'quit' to exit)")

                If Input_STR.ToLower = "quit" Then
                    'Quit!
                    x_end = x
                    x = Ask_Howmany

                ElseIf Input_STR.ToLower = Capital(Y).ToLower Then
                    'Correct
                    Correct = Correct + 1
                    MsgBox("Correct! " & Ask_Howmany - x & " to go!")
                Else
                    'Wrong
                    MsgBox("Incorrect! " & Ask_Howmany - x & " to go!")
                End If
            Next
        Else
            For x = 1 To Ask_Howmany
                Y = rand.Next(0, 49)
                Input_STR = InputBox(Capital(Y) & " is the capital of ... (type 'quit' to exit)")

                If Input_STR.ToLower = "quit" Then
                    'Quit!
                    x_end = x
                    x = Ask_Howmany
                ElseIf Input_STR.ToLower = State(Y).ToLower Then
                    'Correct
                    Correct = Correct + 1

                    MsgBox("Correct! " & Ask_Howmany - x & " to go!")
                Else
                    'Wrong
                    MsgBox("Incorrect! " & Ask_Howmany - x & " to go!")
                End If
            Next
            'End of loop
        End If
        ListView1.Show()
        MsgBox(Correct & " out of " & x_end & " correct!")
    End Sub

    Private Sub Button6_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button6.Click
        Me.Close()
    End Sub

    Private Sub Button2_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button2.Click
        'Find state
        FindInArrays(True)
    End Sub

    Private Sub Organize_Array()
        'Selection sort
        '(numerical/alphabetical and asending/decending)
        Dim index, scan, min As Integer
        Dim temp As String

        If Sorted = False Then
            'Sort
            For index = 0 To State.Length - 2
                min = index

                For scan = index + 1 To State.Length - 1
                    If State(min) > State(scan) Then
                        min = scan
                    End If

                Next
                'State
                temp = State(index)
                State(index) = State(min)
                State(min) = temp
                'Capital
                temp = Capital(index)
                Capital(index) = Capital(min)
                Capital(min) = temp

            Next

            ListView1.View = View.Details

            For x = 0 To 49
                Dim row As New ListViewItem(State(x))
                row.SubItems.Add(Capital(x))

                ListView1.Items.Add(row)
            Next
            Sorted = True
        End If

    End Sub
End Class
