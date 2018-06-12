from django.urls import path


from credit.views.auth import *
from credit.views.addcard import *


app_name="credit"

urlpatterns = [

    path('logout/', logout_view, name="logout"),
    path('login/', LoginView.as_view(), name="login"),
    path('signup/', SignUpView.as_view(), name="signup"),

    #path('credit/', CardView.as_view(), name='credit'),
    path('credit/', CardView.as_view(), name='credit'),

    path('credit/<int:pk>/delete/', DeleteCreditView.as_view(), name='credit_delete'),
    path('credit/<int:pk>/edit/', UpdateCreditView.as_view(), name='credit_edit'),
    path('credit/add_credit/', CreateCreditView.as_view(), name='add_credit'),

        ]