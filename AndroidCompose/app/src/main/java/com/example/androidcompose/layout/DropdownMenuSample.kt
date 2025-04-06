package com.example.androidcompose.layout

import androidx.compose.foundation.layout.Column
import androidx.compose.material.Button
import androidx.compose.material.DropdownMenu
import androidx.compose.material.DropdownMenuItem
import androidx.compose.material.Text
import androidx.compose.runtime.*
import androidx.compose.ui.tooling.preview.Preview

@Composable
fun DropdownMenuSample() {

    var expanded by remember {
        mutableStateOf(false)
    }

    Column() {
        Button(
            onClick = {
                expanded = true
            }
        ) {
            Text(text = "点点滴滴点点滴滴")
        }

        DropdownMenu(
            expanded = expanded,
            onDismissRequest = {
                expanded = false
            }
        ) {
            DropdownMenuItem(
                onClick = {
                    expanded = false
                }
            ) {
                Text(text = "Menu 0")
            }

            DropdownMenuItem(
                onClick = {
                    expanded = false
                }
            ) {
                Text(text = "Menu 1")
            }

            DropdownMenuItem(
                onClick = {
                    expanded = false
                }
            ) {
                Text(text = "Menu 2")
            }
        }
    }
}

@Preview
@Composable
fun DropdownMenuSamplePreview() {
    DropdownMenuSample()
}