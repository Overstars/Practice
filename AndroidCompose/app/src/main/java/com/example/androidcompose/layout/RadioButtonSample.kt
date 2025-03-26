package com.example.androidcompose.layout

import android.annotation.SuppressLint
import androidx.compose.foundation.layout.Column
import androidx.compose.material.Checkbox
import androidx.compose.material.RadioButton
import androidx.compose.runtime.*
import androidx.compose.ui.tooling.preview.Preview
import kotlin.math.ceil

@SuppressLint("UnrememberedMutableState", "RememberReturnType")
@Composable
fun RadioButtonSample() {

    var selected by remember {
        mutableStateOf(
            false
        )
    }

    RadioButton(
        selected = true,
        onClick = {
            selected = !selected
        }
    )

    //多个选项单选
    var checkedList by remember {
        mutableStateOf(
            listOf (
                false, false
            )
        )
    }

    Column() {
        checkedList.forEachIndexed { index, item ->

            RadioButton(selected = item, onClick = {
                checkedList = checkedList.mapIndexed{
                    j, _ -> index == j
                }
            })
        }
    }

    //多个选项多选
    var checkedList2 by remember {
        mutableStateOf(
            listOf (
                false, false
            )
        )
    }

    Column {
        checkedList2.forEachIndexed { index, item ->
            Checkbox(checked = item, onCheckedChange = {
                checkedList2 = checkedList2.mapIndexed{ j, b ->
                    if (index == j)
                        !b
                    else
                        b
                }
            })
        }
    }
}

@Preview
@Composable
fun RadioButtonSamplePreview() {
    RadioButtonSample()
}