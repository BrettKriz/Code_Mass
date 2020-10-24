Public Class Form1

    Private Sub Button1_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button1.Click
        'Arrays
        '*******

        '1. Arrays are variables that can hold multiple
        'values under ONE name
        '2. Arrays can be a grid or a single row
        '3. Rows go across, columns go up and down

        'Create a 1-row (one dimensional) arracy
        Dim arrayEx(5) As Integer    'arrayEx is the name
        'arrayEx = [ 0 0 0 0 0 0 ]
        'Count starts from ZERO, so count is ACTUALLY SIX!!!

        'The particular spots in the array are called
        'indexes. The indexes go from 0 to size
        'In arrayEx we have indexes 0, 1, 2, 3, 4, 5
        '=6 total elements

        'Assign some values to the array
        arrayEx(0) = 4
        arrayEx(1) = -10
        arrayEx(5) = arrayEx(1) + 5

        Dim x As Integer
        x = arrayEx(0)
        arrayEx(x) = 60
        'arrayEx = [4 -10 0 0 60 -5]

        '******RULES******
        '1. Arrays can only hold a single type of data
        'at a time. it can be integers, doubles or strings

        '2. The size of an array can't change while the program is running

        '3. The size of the arracy cannot be a variable
        'Ex: *BAD: Dim Arr(x) as integer *** IES WROUNG!***

        'Output the array using a loop
        '*******************************
        ListView1.View = View.Details

        ListView1.Items.Add("ARRAY CONTENTS:")
        For x = 0 To 5
            ListView1.Items.Add(arrayEx(x))
        Next

        'Use a loop to do some computing array
        '*************************************
        ListView1.Items.Add("NEGATIVES:")
        For x = 0 To 5
            If arrayEx(x) < 0 Then
                ListView1.Items.Add(arrayEx(x))
            End If
        Next

        'Linear Search
        '************************************
        For x = 0 To 5
            If arrayEx(x) = 5 Then
                MsgBox("Found at position: " & x)
            End If
        Next

        'Selection sort
        '(numerical/alphabetical and asending/decending)
        Dim index, scan, temp, min As Integer

        'Sort
        For index = 0 To arrayEx.Length - 2
            min = index
            For scan = index + 1 To arrayEx.Length - 1  'find smallestr (or largest)
                If arrayEx(min) > arrayEx(scan) Then
                    min = scan
                End If
            Next
            'Swap smallest( or largest) element into place
            temp = arrayEx(index)
            arrayEx(index) = arrayEx(min)
            arrayEx(min) = temp
        Next

        'Output the sorted array to a listview
        ListView1.Items.Add("SORTED LIST:")
        For x = 0 To 5
            ListView1.Items.Add(arrayEx(x))
        Next

    End Sub

    Private Sub Button2_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button2.Click
        'create a 2d array
        Dim TwoDEx(2, 4) As Integer '3 rows, 5 cols
        ' God counting from 0 is trippy

        'putting stuff in the array
        TwoDEx(0, 0) = 5
        TwoDEx(1, 3) = -1


        'Automatically go through every element
        'of the arry
        Dim row, col As Integer
        For row = 0 To 2
            For col = 0 To 2
                TwoDEx(row, col) = 10 'set everyone to 10
            Next
        Next

        'Search
        For row = 0 To 2
            For col = 0 To 4
                If TwoDEx(row, col) = -5 Then
                    MsgBox("found at " & row & " " & col)
                End If
            Next
        Next


    End Sub
End Class
