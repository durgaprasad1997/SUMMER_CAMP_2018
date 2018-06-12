from django import forms
from credit.models import *

class CreateCredit(forms.ModelForm):
    class Meta:
        model = creditcard
        exclude = ['id']
        widgets = {

            'name': forms.TextInput(attrs={'class': 'form-control', 'placeholder': 'friendly_name'}),

            'cardname': forms.TextInput(attrs={'class': 'form-control', 'placeholder': 'cardname'}),

            'cvv': forms.TextInput(attrs={'class': 'form-control', 'placeholder': 'cvv'}),

            'cardtype': forms.TextInput(attrs={'class': 'form-control', 'placeholder': 'cardtype'}),
            'cardnumber': forms.TextInput(attrs={'class': 'form-control', 'placeholder': 'cardnumber'}),
            'expiry': forms.TextInput(attrs={'class': 'form-control', 'placeholder': 'expiry'}),

        }

class UpdateCredit(forms.ModelForm):
    class Meta:
        model = creditcard
        exclude = ['id']
        widgets = {

            'name': forms.TextInput(attrs={'class': 'form-control', 'placeholder': 'friendly_name'}),

            'cardname': forms.TextInput(attrs={'class': 'form-control', 'placeholder': 'cardname'}),

            'cvv': forms.TextInput(attrs={'class': 'form-control', 'placeholder': 'cvv'}),

            'cardtype': forms.TextInput(attrs={'class': 'form-control', 'placeholder': 'cardtype'}),
            'cardnumber': forms.TextInput(attrs={'class': 'form-control', 'placeholder': 'cardnumber'}),
            'expiry': forms.TextInput(attrs={'class': 'form-control', 'placeholder': 'expiry'}),

        }