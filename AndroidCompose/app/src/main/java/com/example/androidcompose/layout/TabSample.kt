package com.example.androidcompose.layout

import androidx.compose.foundation.clickable
import androidx.compose.foundation.layout.Column
import androidx.compose.foundation.layout.padding
import androidx.compose.material.*
import androidx.compose.material.icons.Icons
import androidx.compose.material.icons.filled.AccountBox
import androidx.compose.material.icons.filled.AccountCircle
import androidx.compose.runtime.*
import androidx.compose.ui.Modifier
import androidx.compose.ui.graphics.Color
import androidx.compose.ui.input.key.Key.Companion.Tab
import androidx.compose.ui.tooling.preview.Preview
import androidx.compose.ui.unit.dp
import kotlinx.coroutines.selects.select

@Composable
fun TabSample() {

    var selectedTabIndex by remember {
        mutableStateOf(0)
    }

    Column {

        TabRow(selectedTabIndex = selectedTabIndex, divider = {}) {

            Tab(
                selected = selectedTabIndex == 0,
                onClick = { selectedTabIndex = 0 },
                selectedContentColor = Color.Red,
                unselectedContentColor = Color.Black
            ) {
                Text(text = "Tab 0")
            }

            Tab(
                selected = selectedTabIndex == 1,
                onClick = { selectedTabIndex = 1 },
                icon = {
                    Icon(
                        imageVector = Icons.Default.AccountCircle,
                        contentDescription = null
                    )
                },
                text = {
                    Text(text = "Tab 1")
                }
            )

            LeadingIconTab(
                selected = selectedTabIndex == 2,
                onClick = { selectedTabIndex = 2 },
                icon = {
                    Icon(
                        imageVector = Icons.Default.AccountBox,
                        contentDescription = null
                    )
                },
                text = {
                    Text(text = "Tab 2")
                }
            )

//            Text(
//                text = "Tab 1",
//                color = Color.Red,
//                modifier = Modifier
//                    .padding(8.dp)
//                    .clickable {
//                        selectedTabIndex = 0
//                    }
//            )
//
//            Text(
//                text = "Tab 2",
//                modifier = Modifier
//                    .padding(8.dp)
//                    .clickable {
//                        selectedTabIndex = 1
//                    }
//            )
//
//            Text(
//                text = "Tab 3",
//                modifier = Modifier
//                    .padding(8.dp)
//                    .clickable {
//                        selectedTabIndex = 2
//                    }
//            )

        }

        Text(text = "Current Index: $selectedTabIndex")
    }
}

@Preview
@Composable
fun TabSamplePreview() {
    TabSample()
}