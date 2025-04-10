package com.example.androidcompose.layout

import androidx.compose.foundation.layout.Column
import androidx.compose.material.Button
import androidx.compose.material.Text
import androidx.compose.runtime.Composable
import androidx.compose.runtime.CompositionLocalProvider
import androidx.compose.runtime.compositionLocalOf
import androidx.compose.ui.tooling.preview.Preview
import androidx.navigation.compose.NavHost
import androidx.navigation.compose.composable
import androidx.navigation.compose.rememberNavController

@Composable
fun CompositionLocalSample() {

    val navController = rememberNavController()
    val user = User("John Doe")
    CompositionLocalProvider(
        LocalActiveUser provides user
    ) {
        NavHost(
            navController = navController,
            startDestination = "home"
        ) {
            composable("home") {
                HomeScreen{
                    navController.navigate("profile")
                }
            }

            composable("profile") {
                ProfileScreen()
            }
        }
    }


}

@Composable
fun HomeScreen(onTap: () -> Unit) {
    Column {
        Text(text = "Home Screen : ${LocalActiveUser.current.name}")


        Button(onClick = { onTap() }) {
            Text(text = "Go to Profile")
        }
    }
}

@Composable
fun ProfileScreen() {
    Column {
        Text(text = "Profile Screen : ${LocalActiveUser.current.name}")
    }
}

val LocalActiveUser = compositionLocalOf <User>{ error("user is null") }

data class User(val name: String)
@Preview
@Composable
fun CompositionLocalSamplePreview() {
    CompositionLocalSample()
}