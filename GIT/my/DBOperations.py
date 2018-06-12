
import os,sys,django,openpyxl
import click
import MySQLdb
from my import settings
from openpyxl import load_workbook




os.environ.setdefault("DJANGO_SETTINGS_MODULE", 'my.settings')
django.setup()



from credit.models import creditcard




@click.group()
@click.pass_context
def cli(ctx):
    schemaName = settings.DATABASES['default']['NAME']
    print(schemaName)
    print("program started")



@cli.command()
@click.pass_context
def cleardb(ctx):
    print("clearing daata")
    creditcard.objects.all().delete()







@cli.command()
@click.pass_context
def createdb(ctx):
    print("clearing daata")



    schemaName = settings.DATABASES['default']['NAME']
    db = MySQLdb.connect("localhost", "root", "mysql")
    cursor = db.cursor()
    q = "CREATE SCHEMA IF NOT EXISTS "+schemaName
    cursor.execute(q)

    os.system("python manage.py makemigrations")
    os.system("python manage.py migrate")



@cli.command()
@click.pass_context
def dropdb(ctx):

    print("dropping db")
    schemaName = settings.DATABASES['default']['NAME']
    db = MySQLdb.connect("localhost", "root", "mysql",schemaName )
    cursor = db.cursor()
    q = """DROP DATABASE `my`;"""
    cursor.execute(q)

    db.commit()



@cli.command()
@click.pass_context
def populatedb(ctx):
    print("not yet implemented")








if __name__=='__main__':

    cli(obj={})


