from django import forms



class SignUpForm(forms.Form):


    username = forms.CharField(
        max_length=75,
        required=True,
        widget=forms.TextInput(attrs={'class': 'form-control', 'placeholder': 'Enter username'})
    )
    password = forms.CharField(
        max_length=75,
        required=True,
        widget=forms.TextInput(attrs={'class': 'form-control', 'placeholder': 'Enter passsword'})
    )




class LoginForm(forms.Form):
    username = forms.CharField(
        max_length=75,
        required=True,
        widget=forms.TextInput(attrs={'class': 'form-control', 'placeholder': 'Enter First Name'})
    )

    password = forms.CharField(
        max_length=75,
        required=True,
        widget=forms.PasswordInput(attrs={'class': 'form-control', 'placeholder': 'Enter password'})
    )