from django.db import models
from django.contrib.auth.models import User


# Create your models here.


class creditcard(models.Model):
    friendly_name = models.CharField(max_length=128)
    cardname=models.CharField(max_length=128)
    cvv= models.CharField(max_length=128)
    cardtype=models.CharField(max_length=128)
    cardnumber= models.CharField(max_length=128)
    expiry = models.CharField(max_length=128)





    def __str__(self):
        return self.friendly_name
